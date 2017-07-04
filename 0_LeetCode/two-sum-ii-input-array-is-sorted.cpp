/*
167. Two Sum II - Input array is sorted My Submissions QuestionEditorial Solution
Total Accepted: 13041 Total Submissions: 26844 Difficulty: Medium
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int head, tail;
        head = 0; 
        tail = numbers.size()-1;
        
        vector<int> pos;
        while (head<tail) {
            while (numbers[head]+numbers[tail]>target) --tail;
            if (head<tail) {
                if (numbers[head]+numbers[tail]==target) {
                    pos.push_back(head+1);
                    pos.push_back(tail+1);
                    break;
                }
                ++head;
            }
        }
        return pos;
    }
};

