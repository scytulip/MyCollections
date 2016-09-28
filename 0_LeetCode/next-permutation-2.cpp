class Solution {
public:
    // Judge if the sequence is non-increasing from the start position
    bool NoIncrease(vector<int>& nums, vector<int>::iterator start) {
        while (start+1 != nums.end()) {
            if (*start < *(++start)) return false;
        }
        return true;
    }
    void nextPermutation(vector<int>& nums) {
        if (NoIncrease(nums, nums.begin())) {
            // Special case: non-increasing sequence -> last one
            reverse(nums.begin(), nums.end());
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
            vector<int>::iterator i,j;
            i = nums.begin()+1;
            while (i!=nums.end()) {
                if (NoIncrease(nums,i)) {
                    j = nums.end()-1;
                    while (j>i && *j<=*(i-1)) --j;
                    break;
                }
                ++i;
            }
            iter_swap(i-1, j);
            reverse(i, nums.end());
        }
    }
};