class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> myset;
        
        int i;
        for (i=0; i<nums.size(); i++)
        {
            if (myset.find(nums[i]) == myset.end())
            {
                myset.insert(nums[i]);
            } else
            {
                myset.erase(nums[i]);
            }
        }
        
        vector<int> rval;
        rval.push_back(*(myset.begin()));
        rval.push_back(*(++myset.begin()));
        
        return rval;
    }
};