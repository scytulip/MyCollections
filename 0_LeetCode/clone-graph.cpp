/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> gmap;
    void BuildMap(UndirectedGraphNode *node)
    {
        if (node == NULL) return;
        
        gmap[node] = new UndirectedGraphNode(node->label);
        
        vector<UndirectedGraphNode *>::iterator it;
        for (it=node->neighbors.begin(); it!=node->neighbors.end(); it++)
        {
            if (gmap.find(*it)==gmap.end()) BuildMap(*it);
        }
    }
    
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        BuildMap(node);
        
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *>::iterator it;
        vector<UndirectedGraphNode *>::iterator jt;
        for (it=gmap.begin(); it!=gmap.end(); it++)
        {
            for (jt=it->first->neighbors.begin(); jt!=it->first->neighbors.end(); jt++)
            {
                it->second->neighbors.push_back(gmap[*jt]);
            }
        }
        
        return gmap[node];
    }
};