/*
323. Number of Connected Components in an Undirected Graph My Submissions QuestionEditorial Solution
Total Accepted: 8663 Total Submissions: 20054 Difficulty: Medium
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:
     0          3
     |          |
     1 --- 2    4
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:
     0           4
     |           |
     1 --- 2 --- 3
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/

class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> group(n, 0);
        
        int nset = 0;
        int a,b;
        for (auto& p : edges) {
            a = p.first; b = p.second;
            if (group[a]==0 && group[b]==0) {
                ++ nset;
                group[a] = nset;
                group[b] = nset;
            } else if (group[a]==0 && group[b]!=0) {
                group[a] = group[b];
            } else if (group[a]!=0 && group[b]==0) {
                group[b] = group[a];
            } else {
                if (group[a]!=group[b]) {
                    int new_g = min(group[a],group[b]);
                    int old_g = max(group[a],group[b]);
                    for (auto& v : group) if (v==old_g) v=new_g;
                }
            }
        }
        
        for (auto& v : group) if (v==0) v = ++nset;
        
        int count = 0;
        unordered_set<int> used;
        for (auto& v : group) {
            if (used.find(v)==used.end()) {
                used.insert(v);
                ++ count;
            }
        }
        
        return count;
    }
};