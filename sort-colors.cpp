class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a,b,t;
        
        /* swap 0 */
        a = 0; b = nums.size()-1;
        while (a<b)
        {
            while (nums[b]!=0 && a<b) b--;
            while (nums[a]==0 && a<b) a++;
            t = nums[a];
            nums[a] = nums[b];
            nums[b] = t;
        }
        
        /* swap 1 */
        if (nums[a]==0) a++;
        b = nums.size()-1;
        while (a<b)
        {
            while (nums[b]!=1 && a<b) b--;
            while (nums[a]==1 && a<b) a++;
            t = nums[a];
            nums[a] = nums[b];
            nums[b] = t;
        }
    }
};