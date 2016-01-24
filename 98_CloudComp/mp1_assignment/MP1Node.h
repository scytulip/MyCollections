/**********************************
 * FILE NAME: MP1Node.cpp
 *
 * DESCRIPTION: Membership protocol run by this Node.
 * 				Header file of MP1Node class.
 **********************************/

#ifndef _MP1NODE_H_
#define _MP1NODE_H_

#include "stdincludes.h"
#include "Log.h"
#include "Params.h"
#include "Member.h"
#include "EmulNet.h"
#include "Queue.h"

/**
 * Macros
 */
#define TREMOVE 20
#define TFAIL 5

/*
 * Note: You can change/add any functions in MP1Node.{h,cpp}
 */
 
static const int SWIM_T_ACK = 10;
static const int SWIM_T_PRO = 40;   // SWIM protocol total timeout
static const int SWIM_K_RAND = 3;   // SWIM K random processes
static const int LEN_MEMENT_MSG = sizeof(int) + sizeof(short) + sizeof(long) * 2; // Length of MemberListEntry message segment

/**
 * Message Types
 */
enum MsgTypes{
    JOINREQ,    // JOINREQ, member addr, ?, member heartbeat
    JOINREP,    // JOINREP, # of entries, entry_1, ... , entry_k (entry = addr, port, heartbeat, timestamp)
    PING,       // PING, src entry, target entry
    ACK,        // ACK, src entry, target entry
    IND_PING,   // IND_PING, src entry, target entry, relay entry
    IND_ACK,    // IND_ACK, src entry, target entry, relay entry
//    DUMMYLASTMSGTYPE
};

/**
 * STRUCT NAME: MessageHdr
 *
 * DESCRIPTION: Header and content of a message
 */
typedef struct MessageHdr {
	enum MsgTypes msgType;
}MessageHdr;

/**
 * CLASS NAME: MP1Node
 *
 * DESCRIPTION: Class implementing Membership protocol functionalities for failure detection
 */
class MP1Node {
private:
	EmulNet *emulNet;
	Log *log;
	Params *par;
	Member *memberNode;
	char NULLADDR[6];
    // Variables for failure detector
    int cur_list_idx; // Current index of the MemberList for PING
    MemberListEntry cur_ping_entry;

public:
	MP1Node(Member *, Params *, EmulNet *, Log *, Address *);
	Member * getMemberNode() {
		return memberNode;
	}
	int recvLoop();
	static int enqueueWrapper(void *env, char *buff, int size);
	void nodeStart(char *servaddrstr, short serverport);
	int initThisNode(Address *joinaddr);
	int introduceSelfToGroup(Address *joinAddress);
	int finishUpThisNode();
	void nodeLoop();
	void checkMessages();
	bool recvCallBack(void *env, char *data, int size);
	void nodeLoopOps();
	int isNullAddress(Address *addr);
	Address getJoinAddress();
	void initMemberListTable(Member *memberNode);
	void printAddress(Address *addr);
	virtual ~MP1Node();

private:

    /*
     * Convert MemberListEntry to Address object
     */
    inline void entryToAddr(Address *addr, MemberListEntry *ent)
    {
        *(int *)(&addr->addr[0]) = ent->getid();
        *(short *)(&addr->addr[4]) = ent->getport(); 
    }
    
    /*
     * Fill in message with (source entry, target entry)
     */
    inline void fillMsgSrcTgt(char *new_msg, MemberListEntry *srcEnt, MemberListEntry *tgtEnt)
    {
        fillMemberListEntryIntoMsg(new_msg + sizeof(MessageHdr), srcEnt);
        fillMemberListEntryIntoMsg(new_msg + sizeof(MessageHdr) + LEN_MEMENT_MSG, tgtEnt);
    }
    
    /*
     * Fill in message with (source entry, target entry, relay entry)
     */
    inline void fillMsgSrcTgtRly(char *new_msg, MemberListEntry *srcEnt, MemberListEntry *tgtEnt, MemberListEntry *rlyEnt)
    {
        fillMsgSrcTgt(new_msg, srcEnt, tgtEnt);
        fillMemberListEntryIntoMsg(new_msg + sizeof(MessageHdr) + 2*LEN_MEMENT_MSG, rlyEnt);
    }

    int updateMemberInList(MemberListEntry *memEnt);
    void getSelfMemberListEntry(MemberListEntry *memEnt);
    void fillMemberListEntryIntoMsg(char *msg, MemberListEntry *memEnt);
    void parseMsgMemberListEntry(char *msg, MemberListEntry *memEnt);
};

#endif /* _MP1NODE_H_ */
