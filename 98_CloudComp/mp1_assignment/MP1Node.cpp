/**********************************
 * FILE NAME: MP1Node.cpp
 *
 * DESCRIPTION: Membership protocol run by this Node.
 * 				Definition of MP1Node class functions.
 **********************************/

#include "MP1Node.h"

/*
 * Note: You can change/add any functions in MP1Node.{h,cpp}
 */

static const int SWIM_T_ACK = 10;
static const int SWIM_T_PRO = 50;   // SWIM protocol total timeout
static const int SWIM_K_RAND = 4;   // SWIM K random processes
static const int LEN_MEMENT_MSG = sizeof(int) + sizeof(short) + sizeof(long) * 2; // Length of MemberListEntry message segment

/**
 * Overloaded Constructor of the MP1Node class
 * You can add new members to the class if you think it
 * is necessary for your logic to work
 */
MP1Node::MP1Node(Member *member, Params *params, EmulNet *emul, Log *log, Address *address) {
	for( int i = 0; i < 6; i++ ) {
		NULLADDR[i] = 0;
	}
	this->memberNode = member;
	this->emulNet = emul;
	this->log = log;
	this->par = params;
	this->memberNode->addr = *address;
}

/**
 * Destructor of the MP1Node class
 */
MP1Node::~MP1Node() {}

/**
 * FUNCTION NAME: recvLoop
 *
 * DESCRIPTION: This function receives message from the network and pushes into the queue
 * 				This function is called by a node to receive messages currently waiting for it
 */
int MP1Node::recvLoop() {
    if ( memberNode->bFailed ) {
    	return false;
    }
    else {
    	return emulNet->ENrecv(&(memberNode->addr), enqueueWrapper, NULL, 1, &(memberNode->mp1q));
    }
}

/**
 * FUNCTION NAME: enqueueWrapper
 *
 * DESCRIPTION: Enqueue the message from Emulnet into the queue
 */
int MP1Node::enqueueWrapper(void *env, char *buff, int size) {
	Queue q;
	return q.enqueue((queue<q_elt> *)env, (void *)buff, size);
}

/**
 * FUNCTION NAME: nodeStart
 *
 * DESCRIPTION: This function bootstraps the node
 * 				All initializations routines for a member.
 * 				Called by the application layer.
 */
void MP1Node::nodeStart(char *servaddrstr, short servport) {
    Address joinaddr;
    joinaddr = getJoinAddress();

    // Self booting routines
    if( initThisNode(&joinaddr) == -1 ) {
#ifdef DEBUGLOG
        log->LOG(&memberNode->addr, "init_thisnode failed. Exit.");
#endif
        exit(1);
    }

    if( !introduceSelfToGroup(&joinaddr) ) {
        finishUpThisNode();
#ifdef DEBUGLOG
        log->LOG(&memberNode->addr, "Unable to join self to group. Exiting.");
#endif
        exit(1);
    }

    return;
}

/**
 * FUNCTION NAME: initThisNode
 *
 * DESCRIPTION: Find out who I am and start up
 */
int MP1Node::initThisNode(Address *joinaddr) {
	/*
	 * This function is partially implemented and may require changes
	 */
	//int id = *(int*)(&memberNode->addr.addr);
	//int port = *(short*)(&memberNode->addr.addr[4]);

	memberNode->bFailed = false;
	memberNode->inited = true;
	memberNode->inGroup = false;
    // node is up!
	memberNode->nnb = 0;
	memberNode->heartbeat = 0;
	memberNode->pingCounter = TFAIL;
	memberNode->timeOutCounter = -1;
    initMemberListTable(memberNode);

    cur_iter = memberNode->memberList.begin();

    return 0;
}

/**
 * FUNCTION NAME: introduceSelfToGroup
 *
 * DESCRIPTION: Join the distributed system
 */
int MP1Node::introduceSelfToGroup(Address *joinaddr) {
	MessageHdr *msg;
#ifdef DEBUGLOG
    static char s[1024];
#endif

    if ( 0 == memcmp((char *)&(memberNode->addr.addr), (char *)&(joinaddr->addr), sizeof(memberNode->addr.addr))) {
        // I am the group booter (first process to join the group). Boot up the group
#ifdef DEBUGLOG
        log->LOG(&memberNode->addr, "Starting up group...");
#endif
        memberNode->inGroup = true;
    }
    else {
        size_t msgsize = sizeof(MessageHdr) + sizeof(joinaddr->addr) + sizeof(long) + 1;
        msg = (MessageHdr *) malloc(msgsize * sizeof(char));

        // create JOINREQ message: format of data is {struct Address myaddr}
        msg->msgType = JOINREQ;
        memcpy((char *)msg + sizeof(MessageHdr), &memberNode->addr.addr, sizeof(memberNode->addr.addr));
        memcpy((char *)msg + sizeof(MessageHdr) + 1 + sizeof(memberNode->addr.addr), &memberNode->heartbeat, sizeof(long));

#ifdef DEBUGLOG
        sprintf(s, "Trying to join...");
        log->LOG(&memberNode->addr, s);
#endif

        // send JOINREQ message to introducer member
        emulNet->ENsend(&memberNode->addr, joinaddr, (char *)msg, msgsize);

        free(msg);
    }

    return 1;

}

/**
 * FUNCTION NAME: finishUpThisNode
 *
 * DESCRIPTION: Wind up this node and clean up state
 */
int MP1Node::finishUpThisNode(){
   /*
    * Your code goes here
    */

   return 0;
}

/**
 * FUNCTION NAME: nodeLoop
 *
 * DESCRIPTION: Executed periodically at each member
 * 				Check your messages in queue and perform membership protocol duties
 */
void MP1Node::nodeLoop() {
    if (memberNode->bFailed) {
    	return;
    }

    // Check my messages
    checkMessages();

    // Wait until you're in the group...
    if( !memberNode->inGroup ) {
    	return;
    }

    // ...then jump in and share your responsibilites!
    nodeLoopOps();

    return;
}

/**
 * FUNCTION NAME: checkMessages
 *
 * DESCRIPTION: Check messages in the queue and call the respective message handler
 */
void MP1Node::checkMessages() {
    void *ptr;
    int size;

    // Pop waiting messages from memberNode's mp1q
    while ( !memberNode->mp1q.empty() ) {
    	ptr = memberNode->mp1q.front().elt;
    	size = memberNode->mp1q.front().size;
    	memberNode->mp1q.pop();
    	recvCallBack((void *)memberNode, (char *)ptr, size);
    }
    return;
}

/**
 * FUNCTION NAME: recvCallBack
 *
 * DESCRIPTION: Message handler for different message types
 */
bool MP1Node::recvCallBack(void *env, char *data, int size ) {
	/*
	 * Your code goes here
	 */

    MemberListEntry selfEnt(
            (int)memberNode->addr.addr[0], 
            (short)memberNode->addr.addr[4], 
            0, par->getcurrtime());

    switch(((MessageHdr *)data)->msgType)
    {
        case JOINREQ:
        {
            // Extract request address and add it into MemberList
            Address req_addr;
            memcpy(&req_addr, data + sizeof(MessageHdr), sizeof(req_addr.addr));
            
            MemberListEntry memEnt(
                    (int)req_addr.addr[0], (short)req_addr.addr[4], 0, par->getcurrtime());
            if(updateMemberInList(&memEnt))
                log->logNodeAdd(&memberNode->addr, &req_addr);
            
            // create JOINREP message: include the list of all members
            int numMembers = memberNode->memberList.size() + 1; // Add self
            
            size_t msg_size = sizeof(MessageHdr) + sizeof(int) + numMembers*LEN_MEMENT_MSG;
            char* new_msg = (char *)malloc(msg_size * sizeof(char));
            ((MessageHdr *)new_msg)->msgType = JOINREP;

            *(int *)(new_msg + sizeof(MessageHdr)) = numMembers;
            fillMemberListEntryIntoMsg(new_msg + sizeof(MessageHdr) + sizeof(int), &selfEnt);

            for (int i = 0; i < memberNode->memberList.size(); i++)
            {
                fillMemberListEntryIntoMsg(
                        new_msg + sizeof(MessageHdr) + sizeof(int) + (i+1)*LEN_MEMENT_MSG,
                        &memberNode->memberList[i]);
            }

            //send JOINREP message to introducer member
            Address rep_addr;
            for (int i = 0; i < memberNode->memberList.size(); i++)
            {
                entryToAddr( &rep_addr, &(memberNode->memberList[i]) );
                emulNet->ENsend(&memberNode->addr, &rep_addr, new_msg, msg_size);
            }

            free(new_msg);
            break;
        }
        case JOINREP:
        {
            int numMembers = *(int *)(data + sizeof(MessageHdr));
            MemberListEntry memEnt;
            Address rep_addr;
            
            // Retrieve member list from the message
            for (int i = 0; i < numMembers; i++)
            {
                parseMsgMemberListEntry(
                        data + sizeof(MessageHdr) + sizeof(int) + i*LEN_MEMENT_MSG, &memEnt);
                entryToAddr( &rep_addr, &memEnt );
                if (memEnt.getid() == (int)memberNode->addr.addr[0]) continue; // Don't add self into the list
                if (updateMemberInList(&memEnt))
                    log->logNodeAdd(&memberNode->addr, &rep_addr);
            } 

            break;
        }
        case PING:
        {
            break;
        }
        case ACK:
        {
            break;
        }
    }
    
    free(data);

    return true;

}

/**
 * FUNCTION NAME: nodeLoopOps
 *
 * DESCRIPTION: Check if any node hasn't responded within a timeout period and then delete
 * 				the nodes
 * 				Propagate your membership list
 */
void MP1Node::nodeLoopOps() {

	/*
	 * Your code goes here
	 */

    MemberListEntry selfEnt(
        (int)memberNode->addr.addr[0], 
        (short)memberNode->addr.addr[4], 
        0, par->getcurrtime());

    long ping_timestamp = cur_ping_entry.gettimestamp();

    if ( 0 == ping_timestamp ) // Require a new Ping
    { 
        // Start a new ping

        if (cur_iter == memberNode->memberList.end())
            cur_iter = memberNode->memberList.begin();
        else
            cur_iter ++;

        if (cur_iter == memberNode->memberList.end()) // Empty list
            return;

        // Send direct PING
        size_t msg_size = sizeof(MessageHdr) + 2 * LEN_MEMENT_MSG;
        char* new_msg = (char *)malloc(msg_size * sizeof(char));
        ((MessageHdr *)new_msg)->msgType = PING;

        fillMemberListEntryIntoMsg(new_msg + sizeof(MessageHdr), &selfEnt);
        cur_ping_entry = (*cur_iter);
        cur_ping_entry.settimestamp(par->getcurrtime());
        fillMemberListEntryIntoMsg(new_msg + sizeof(MessageHdr) + LEN_MEMENT_MSG, &cur_ping_entry);

        Address rec_addr;
        entryToAddr(&rec_addr, &cur_ping_entry);
        emulNet->ENsend(&memberNode->addr, &rec_addr, new_msg, msg_size);
        free(new_msg);

    } else if ( par->getcurrtime() - cur_ping_entry.gettimestamp() > SWIM_T_ACK )
    {
        // ACK timeout, start indirect ping
    } else if ( par->getcurrtime() - cur_ping_entry.gettimestamp() > SWIM_T_PRO )
    {
        // Protocol timeout, delete pinged node
    }

    return;
}

/**
 * FUNCTION NAME: isNullAddress
 *
 * DESCRIPTION: Function checks if the address is NULL
 */
int MP1Node::isNullAddress(Address *addr) {
	return (memcmp(addr->addr, NULLADDR, 6) == 0 ? 1 : 0);
}

/**
 * FUNCTION NAME: getJoinAddress
 *
 * DESCRIPTION: Returns the Address of the coordinator
 */
Address MP1Node::getJoinAddress() {
    Address joinaddr;

    memset(&joinaddr, 0, sizeof(Address));
    *(int *)(&joinaddr.addr) = 1;
    *(short *)(&joinaddr.addr[4]) = 0;

    return joinaddr;
}

/**
 * FUNCTION NAME: initMemberListTable
 *
 * DESCRIPTION: Initialize the membership list
 */
void MP1Node::initMemberListTable(Member *memberNode) {
	memberNode->memberList.clear();
}

/**
 * FUNCTION NAME: printAddress
 *
 * DESCRIPTION: Print the Address
 */
void MP1Node::printAddress(Address *addr)
{
    printf("%d.%d.%d.%d:%d \n",  addr->addr[0],addr->addr[1],addr->addr[2],
                                                       addr->addr[3], *(short*)&addr->addr[4]) ;    
}

/**
 * FUNCTION NAME: updateMemberInList
 *
 * DESCRIPTION: Update a member in the memberList with the newest timestamp, if not existed, add a new one.
 *              Return 1 if updated.
 */
int MP1Node::updateMemberInList(MemberListEntry *memEnt)
{
    // Find if the member is already in the list.
    vector<MemberListEntry>::iterator i;
    for (i = memberNode->memberList.begin(); i != memberNode->memberList.end(); i++)
    {
        if ((*memEnt).getid() == (*i).getid())
        {
            if ((*memEnt).gettimestamp() < (*i).gettimestamp())
            {
                (*i) = (*memEnt);
                (*i).settimestamp(par->getcurrtime());
                return 1;
            } else
                return 0;
        }
    }

    // Add an entry if not in the list.
    if (i == memberNode->memberList.end())
        memberNode->memberList.push_back(*memEnt);
    return 1;
}
/**
 * FUNCTION NAME: getSelfMemberListEntry
 *
 * DESCRIPTION: Get self MemberListEntry.
 */
void MP1Node::getSelfMemberListEntry(MemberListEntry *memEnt)
{
    memEnt->setid((int)memberNode->addr.addr[0]);
    memEnt->setport((short)memberNode->addr.addr[4]);
    memEnt->setheartbeat(memberNode->heartbeat);
    memEnt->settimestamp(par->getcurrtime());
}

/**
 * FUNCTION NAME: fillMemberListEntryIntoMsg
 *
 * DESCRIPTION: Fill in the message pointer with MemberListEntry info.
 */
void MP1Node::fillMemberListEntryIntoMsg(char *msg, MemberListEntry *memEnt)
{
    int id = memEnt->getid();
    short port = memEnt->getport();
    long heartbeat = memEnt->getheartbeat();
    long timestamp = memEnt->gettimestamp();
    memcpy((char *)msg, &id, sizeof(int));
    memcpy((char *)msg + sizeof(int), &port, sizeof(short));
    memcpy((char *)msg + sizeof(int) + sizeof(short), &heartbeat, sizeof(long));
    memcpy((char *)msg + sizeof(int) + sizeof(short) + sizeof(long), &timestamp, sizeof(long));
}

/**
 * FUNCTION NAME: parseMsgMemberListEntry
 *
 * DESCRIPTION: Parse MemberListEntry info from a message pointer.
 */
void MP1Node::parseMsgMemberListEntry(char *msg, MemberListEntry *memEnt)
{
    memEnt->setid(*(int*)msg);
    memEnt->setport(*(short*)(msg + sizeof(int)));
    memEnt->setheartbeat(*(long*)(msg + sizeof(int) + sizeof(short)));
    memEnt->settimestamp(*(long*)(msg + sizeof(int) + sizeof(short) + sizeof(long)));
}

