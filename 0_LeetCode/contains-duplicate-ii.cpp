class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> myset;
        int i;
        
        for (i=0; i<nums.size(); i++)
        {
            if (myset.find(nums[i])!=myset.end() && i-myset[nums[i]]<=k)
            {
                return true;
            } else
            {
                myset[nums[i]] = i;
            }
        }
        
        return false;
    }
};