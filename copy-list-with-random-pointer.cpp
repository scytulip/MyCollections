/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode*, RandomListNode*> node_map;
        map<RandomListNode*, RandomListNode*>::iterator it;
        RandomListNode *pt, *idx;
        
        if (head==NULL) return NULL;
        
        pt = head;
        while (pt!=NULL)
        {
            node_map.insert(pair<RandomListNode*, RandomListNode*>(pt, new RandomListNode(pt->label)));
            
            pt = pt->next;
        }
        
        pt = head;
        while (pt!=NULL)
        {
            it = node_map.find(pt);
            idx = (*it).second;
            
            if (pt->next==NULL)
                idx->next = NULL;
            else
            {
                it = node_map.find(pt->next);
                idx->next = (*it).second;
            }
            
            if (pt->random==NULL)
                idx->random = NULL;
            else
            {
                it = node_map.find(pt->random);
                idx->random = (*it).second;
            }
            
            pt = pt->next;
        }
        
        it = node_map.find(head);
        return (*it).second;
    }
};