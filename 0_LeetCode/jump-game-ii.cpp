class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size()<=1) return 0;
        
        int n = nums.size();
        int i,j,v;
        vector<int> step(nums.size(), 0);
        
        for (i=0; i<n-1; i++)
        {
            v = i+nums[i];
            if (v>=n-1) return step[i]+1;
            for (j=v; j>i; j--)
            {
                if (step[j]==0) 
                    step[j] = step[i]+1;
                else
                    break;
            }
        }
        
        return step[n-1];
    }
};