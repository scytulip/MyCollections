class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mymap;
        int i;
        
        for (i=0; i<nums.size(); i++)
        {
            if (mymap.find(nums[i])==mymap.end())
                mymap[nums[i]] = 1;
            else if (mymap[nums[i]] == 1)
                mymap[nums[i]] = 2;
            else
                mymap.erase(nums[i]);
        }
        
        return (mymap.begin())->first;
    }
};