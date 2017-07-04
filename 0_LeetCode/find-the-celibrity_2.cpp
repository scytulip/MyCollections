// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        if (n==1) return -1;
        
        int remain = 0;
        for (int i=1; i<n; ++i)
            if (knows(remain, i)) remain = i;
        
        for (int i=0; i<n; ++i)
            if (i!=remain) {
                if (!knows(i, remain)) return -1;
                if (knows(remain, i)) return -1;
            }
        return remain;
    }
};