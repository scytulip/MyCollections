class Solution {
public:
    int rob(vector<int>& nums) {
        int i,j;
        
        if (nums.size()==0) return 0;
        else if (nums.size()==1) return nums[0];
        else if (nums.size()==2) return (nums[0]>nums[1]) ? nums[0]:nums[1];
        else if (nums.size()==3) return (nums[0]+nums[2]>nums[1]) ? nums[0]+nums[2]:nums[1];
        else { 
            nums[2] += nums[0];
            for (i=3; i<nums.size(); i++) {
                nums[i] += ((nums[i-2]>nums[i-3]) ? nums[i-2] : nums[i-3]);
            }
            return ((nums[i-1]>nums[i-2]) ? nums[i-1] : nums[i-2]);
        }
    }
};