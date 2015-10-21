class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k==0) return;
        
        vector<int> tmp(nums.begin(), nums.end()-k);
        nums.erase(nums.begin(), nums.end()-k);
        nums.insert(nums.end(), tmp.begin(), tmp.end());
    }
};