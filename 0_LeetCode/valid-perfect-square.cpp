/*
367. Valid Perfect Square  QuestionEditorial Solution  My Submissions
Total Accepted: 6626
Total Submissions: 18178
Difficulty: Medium
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False
Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num==0 || num==1) return true;
        
        long long left = 0;
        long long right = num;
        long long half = (left+right)/2;
        
        while (half!=left && half!=right) {
            if (half*half>num)
                right = half;
            else if (half*half<num)
                left = half;
            else
                return true;
            half = (left+right)/2;
        }
        
        return false;
    }
};