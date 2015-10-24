class Solution {
private:
public:
    int numSquares(int n) {
        int i = 1;
        int j;
        int v;
        unordered_set<int> myset, newset;
        unordered_set<int>::iterator it;
        
        i = 1;
        myset.insert(n);
        while (1) {
            for (it=myset.begin(); it!=myset.end(); it++)
                for (j=1; j*j<=(*it); j++)
                {
                    v = (*it)-j*j;
                    newset.insert(v);
                    if (v==0) return i;
                }
            myset = newset;
            i ++;
        }
        
        return i;
    }
};