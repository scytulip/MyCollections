/*
305. Number of Islands II  QuestionEditorial Solution  My Submissions
Total Accepted: 7998
Total Submissions: 22598
Difficulty: Hard
A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
We return the result as an array: [1, 1, 2, 3]

Challenge:

Can you do it in time complexity O(k log mn), where k is the length of the positions?
*/

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        if (positions.empty()) return vector<int>();

        vector<int> result;
        const vector<int> dx = {0, 0, 1, -1};
        const vector<int> dy = {1, -1, 0, 0};
        
        vector<vector<int>> map(m+2, vector<int>(n+2, INT_MAX));
        vector<int> list = {INT_MAX};
        
        int island_count = 0;
        int index = 0;
        int x, y;
        
        for (const auto& p : positions) {
            x = p.first+1;
            y = p.second+1;
            if (map[x][y]==INT_MAX) {
                int mi = INT_MAX;
                for (int i=0; i<4; ++i) mi = min(mi, map[x+dx[i]][y+dy[i]]);
                if (mi==INT_MAX) {
                    ++island_count;
                    ++index;
                    list.push_back(index);
                    map[x][y] = index;
                } else {
                    unordered_set<int> set;
                    for (int i=0; i<4; ++i) {
                        int k = map[x+dx[i]][y+dy[i]];
                        if (k!=INT_MAX) set.insert(Root(list, k));
                    }
                    island_count -= (set.size()-1);
                    auto it = ++set.begin();
                    while(it != set.end()) {
                        list[*it] = *(set.begin());
                        ++it;
                    }
                    map[x][y] = *set.begin();
                }
            }
            result.push_back(island_count);
        }
        return result;
    }
private:
    int Root(vector<int>& vec, int idx) {
        if (idx == vec[idx])
            return idx;
        else {
            vec[idx] = Root(vec, vec[idx]);
            return vec[idx];
        }
    }
};