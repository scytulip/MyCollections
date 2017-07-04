/*
253. Meeting Rooms II  QuestionEditorial Solution  My Submissions
Total Accepted: 13361
Total Submissions: 37476
Difficulty: Medium
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(),
             [](const Interval& a, const Interval& b){return a.start<b.start;});
             
        vector<int> list;
        for (const auto& i : intervals) {
            bool mark = false;
            for (auto& l : list) {
                if (l<=i.start) {
                    l = i.end;
                    mark = true;
                    break;
                }
            }
            if (!mark) list.push_back(i.end);
        }
        
        return list.size();
    }
};
