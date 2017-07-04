class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> in_edge(numCourses, 0);
        vector<list<int>> graph(numCourses, list<int>());
        for (const auto& p : prerequisites) {
            if (p.first==p.second) return vector<int>();
            ++in_edge[p.first];
            graph[p.second].push_back(p.first);
        }
        
        unordered_set<int> cand;
        for (int i=0; i<numCourses; ++i) if (in_edge[i]==0) cand.insert(i);
        
        int val;
        vector<int> list;
        while(!cand.empty()) {
            val = *cand.begin();
            cand.erase(cand.begin());
            in_edge[val] = -1;
            list.push_back(val);
            
            for (const auto& l : graph[val]) {
                --in_edge[l];
                if (in_edge[l]==0) cand.insert(l);
            }
        }
        
        for (const auto& i : in_edge) if (i>0) return vector<int>();
        return list;
    }
};