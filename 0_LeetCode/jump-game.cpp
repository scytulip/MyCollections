class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i, v;
        int n = nums.size();
        int last = 0;
        
        for (i=0; (i<n && i<=last); i++)
        {
            v = i+nums[i];
            if (v>last) last=v;
        }
        
        return (last >= n-1);
    }
};