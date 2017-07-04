/*
261. Graph Valid Tree My Submissions QuestionEditorial Solution
Total Accepted: 13580 Total Submissions: 40767 Difficulty: Medium
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

Hint:

Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return? Is this case a valid tree?
According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (n<=1 && edges.empty()) return true;
        
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
                if (group[a]==group[b]) {
                    return false;
                } else {
                    int new_g = min(group[a],group[b]);
                    int old_g = max(group[a],group[b]);
                    for (auto& v : group) if (v==old_g) v=new_g;
                }
            }
        }
        
        for (auto& v : group) if (v!=1) return false;
        return true;
    }
};