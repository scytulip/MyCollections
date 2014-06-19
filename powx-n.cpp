/*

Implement pow(x, n).

*/


class Solution {
public:
    double pow(double x, int n) {
        /* Ex:
          2^11 = (2*2)^5 * 2 = (4*4)^2 * (4*2) = left(16*16) * right(4*2)
        */
        
        double left = x;
        double right = 1;
        
        if (n<0) return 1/(x*pow(x,-n-1)); // Avoid binary overflow!!!!
        
        if (!n) return 1;
        
        while (n>1)
        {
            if (n%2==1) right *= left;
            left = left * left;
            n = n/2;
        }
        
        return left * right;
    }
};