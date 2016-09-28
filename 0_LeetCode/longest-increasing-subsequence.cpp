class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (!nums.size()) return 0;
        
        vector<int> rec(nums.size(), 0);
        
        int max = 1;
        int i,j;
        for (i=0; i<nums.size(); ++i) {
            for (j=i-1; j>=0; --j)
                if (nums[i]>nums[j] && rec[j]+1>rec[i]) {
                    rec[i]=rec[j]+1;
                    if (rec[i]>max) max = rec[i];
                }
            if (rec[i]==0) rec[i]=1;
        }
        
        return max;
    }
};