class Solution {
public:
    // Reference http://bookshadow.com/weblog/2014/12/30/leetcode-factorial-trailing-zeroes/
    int trailingZeroes(int n) {
        long div = 5;
        long val = 0;
        while (n>=div) {
            val += (n/div);
            div *= 5;
        }
        return val;
    }
};