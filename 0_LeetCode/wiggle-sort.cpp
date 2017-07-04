class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for (int i=(nums.size()-1)/2; i>0; --i) {
            int t = nums[i*2];
            nums[i*2] = nums[i];
            nums[i] = t;
        }
    }
};