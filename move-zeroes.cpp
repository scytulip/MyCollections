class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos, i;
        pos = 0;
        
        if (nums.size() == 0) return;
        
        for (i = 1; i < nums.size(); i++)
            if (nums[i] != 0)
            {
                while(pos<i && nums[pos]!=0) pos ++;
                if (nums[pos] == 0)
                {
                    nums[pos] = nums[i];
                    nums[i] = 0;
                    pos ++;
                }
            }
    }
};