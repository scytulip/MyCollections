class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        int i;
        
        for (i=0; i<nums.size(); i++)
        {
            if (set.find(nums[i]) != set.end()) return true;
            set.insert(nums[i]);
        }
        
        return false;
    }
};