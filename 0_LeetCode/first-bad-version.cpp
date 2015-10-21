// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int a = 1;
        int b = n;
        int c = 0;
        
        while (b-a>1)
        {
            c = a + (b-a)/2; // Overflow issue!
            
            if (isBadVersion(c))
                b = c;
            else
                a = c;
        }
        
        return isBadVersion(a) ? a : b;
    }
};