class Solution {
public:
    vector<int> grayCode(int n) {
        
        vector<int> rt_val;
        int i;
        
        rt_val.push_back(0);
        if (n<1) return rt_val;
        
        rt_val.push_back(1);
        if (n==1) return rt_val;
        
        rt_val = grayCode(n-1);
        
        for (i=rt_val.size()-1; i>=0; i--)
        {
            rt_val.push_back(rt_val[i]+(1<<(n-1)));
        }
        
        return rt_val;
    }
};