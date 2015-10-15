class Solution {
public:
    bool isPalindrome(int x) {
        
        int val = x;
        int dig = 1;
        
        if (x<0) return false;
        
        /* Count # of digits */
        while( (dig != 1000000000) && (val/(dig*10) != 0) )
        {
            dig *= 10;
        }
        
        /* Check Palindrome */
        while(val!=0 && dig>0)
        {
            if ( (val/dig != val%10) ) return false;
            val %= dig;
            val /= 10;
            dig /= 100;
        }
        
        return true;
    }
};