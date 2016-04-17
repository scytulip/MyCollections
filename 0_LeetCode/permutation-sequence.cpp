class Solution {
public:
    string getPermutation(int n, int k) {
        string rt_val = "";
        bool used[10] = {0}; //Set of used numbers
        
        int i;
        int pt_left = 1;
        // # of permutations left
        for (i=1; i<=n; ++i) { 
            pt_left *= i; 
        } 
        
        int j;
        for (i=n; i>=1; --i) {
            pt_left /= i;
            for (j=1; j<=n; ++j) if (!used[j]) {
                if (k-pt_left > 0) {
                    k -= pt_left;
                } else {
                    used[j] = true;
                    rt_val += (j+'0');
                    break;
                }
            }
        }
        
        return rt_val;
    }
};