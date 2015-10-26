class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        long i = 1;
        long val = 0;
        
        
        while (n/i>0)
        {
            if (m/i == n/i) val += (m/i)%2*i;
            if (i==1073741824) break;
            i *= 2;
        }
        
        return val;
    }
};