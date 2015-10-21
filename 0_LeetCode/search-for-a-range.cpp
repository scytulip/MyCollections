class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int start, end, pv;
        int a, b;
        vector<int> rt_val;
        
        /* Binary Search */
        start = 0; end = n-1;
        while (start<end) // find the lower bound
        {
            pv = (start+end)/2;
            if (A[pv]<target)
                start = pv+1;
            else
                end = pv-1;
        }
        if (A[start]<target)
            a = start+1;
        else
            a = start;
            
        start = 0; end = n-1;
        while (start<end) // find the higher bound
        {
            pv = (start+end)/2;
            if (A[pv]>target)
                end = pv-1;
            else
                start = pv+1;
        }
        if (A[start]>target)
            b = start-1;
        else
            b = start;
            
        if (a<=b)
        {
            rt_val.push_back(a);
            rt_val.push_back(b);
        } else
        {
            rt_val.push_back(-1);
            rt_val.push_back(-1);
        }
            
        return rt_val;
        
    }
};