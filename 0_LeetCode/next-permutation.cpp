class Solution {
public:
    // Judge if the sequence is non-increasing from the start position
    bool NoIncrease(vector<int>& nums, int start) {
        for (int i=start; i<nums.size()-1; ++i) {
            if (nums[i]<nums[i+1]) return false;
        }
        return true;
    }
    void nextPermutation(vector<int>& nums) {
        if (NoIncrease(nums, 0)) {
            // Special case: non-increasing sequence -> last one
            int i = 0; int j = nums.size()-1;
            while (i<j) {
                swap(nums[i], nums[j]);
                ++ i; --j;
            }
        } else {
            // 1,3(i-1),(5,4,2)
            //  5,4,2 is the non-ascending sub array. 
            //  Starting from the right hand side, 
            //  swap the first # that is larger than (i-1)th # with (i-1)th #.
            //
            // 1,4,(5,3,2)
            //  Then, sort the sub array.
            //
            // 1,4,(2,3,5)
            int i = 1, j, t;
            while (i<nums.size()) {
                if (NoIncrease(nums, i)) {
                    j = nums.size()-1;
                    while (j>i && nums[j]<=nums[i-1]) --j;
                    break;
                }
                ++i;
            }
            swap(nums[i-1], nums[j]);
            j = nums.size()-1;
            while (i<j) { // Reorder the sub array
                swap(nums[i], nums[j]);
                ++i; --j;
            }
        }
    }
private:
    void swap(int& a, int& b) {
        int t;
        t = a; a = b; b = t;
    }
};