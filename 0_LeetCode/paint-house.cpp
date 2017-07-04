/*
256. Paint House My Submissions QuestionEditorial Solution
Total Accepted: 8848 Total Submissions: 20441 Difficulty: Medium
There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.
*/

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        
        int n = costs.size();
        vector<int> paint(3,0);
        vector<int> np(3,0);
        
        paint = {costs[0][0], costs[0][1], costs[0][2]};
        for (int i=1; i<n; ++i) {
            np[0] = min(paint[1], paint[2])+costs[i][0];
            np[1] = min(paint[0], paint[2])+costs[i][1];
            np[2] = min(paint[0], paint[1])+costs[i][2];
            paint = np;
        }
        
        return min(paint[0], min(paint[1], paint[2]));
    }
};