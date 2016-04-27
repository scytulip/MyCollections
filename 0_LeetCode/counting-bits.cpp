class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> rt_val;
        rt_val.resize(num+1);
        rt_val[0] = 0;
        
        int bin = 1;
        
        for (int i=1; i<=num; i++) {
            if (i==bin) bin*=2;
            rt_val[i] = rt_val[i-bin/2]+1;
        }
        
        return rt_val;
    }
};