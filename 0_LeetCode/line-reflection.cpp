/*
356. Line Reflection  QuestionEditorial Solution  My Submissions
Total Accepted: 1657
Total Submissions: 5980
Difficulty: Medium
Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.

Example 1:
Given points = [[1,1],[-1,1]], return true.

Example 2:
Given points = [[1,1],[-1,-1]], return false.

Follow up:
Could you do better than O(n2)?

Hint:

Find the smallest and largest x-value for all points.
If there is a line then it should be at y = (minX + maxX) / 2.
For each point, make sure that it has a reflected point in the opposite side.
Credits:
Special thanks to @memoryless for adding this problem and creating all test cases.
*/

class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if (points.empty()) return true;
        
        int minx = INT_MAX;
        int maxx = INT_MIN;
        for (auto& p : points) {
            p.first *= 2; // Avoid float
            minx = min(minx, p.first);
            maxx = max(maxx, p.first);
        }
        int center = (minx + maxx)/2;
        for (auto& p : points) p.first -= center;
        
        sort(points.begin(), points.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return (a.second != b.second) ? (a.second < b.second) : (abs(a.first)<abs(b.first));
             });
        
        int px = 0, py = 0;
        int plus = 1, minus = 1;
        for (int i=0; i<points.size(); ++i) {
            if (px!=abs(points[i].first) || py!=points[i].second) {
                if (!(plus>0 && minus>0)) return false;
                px = abs(points[i].first);
                py = points[i].second;
                plus = 0;
                minus = 0;
            }
            plus += (points[i].first>=0);
            minus += (points[i].first<=0);
        }
        
        return (plus>0 && minus>0);
    }
};