/*
325. Maximum Size Subarray Sum Equals k  QuestionEditorial Solution  My Submissions
Total Accepted: 7833
Total Submissions: 19381
Difficulty: Medium
Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time?
*/

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int sum = 0;
        int max_len = 0;
        unordered_map<int, int> map;
        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];
            if (map.find(sum)==map.end()) map[sum]=i;
            if (sum==k) {
                max_len = max(max_len, i+1);
            } else {
                if (map.find(sum-k)!=map.end()) {
                    max_len = max(max_len, i-map[sum-k]);
                }
            }
        }
        return max_len;
    }
};