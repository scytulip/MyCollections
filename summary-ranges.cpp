class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i;
        int hd_pos = -1;
        string s;
        vector<string> slist;
        
        for (i=0; i<nums.size(); i++)
        {
            if (hd_pos == -1)
            {
                s += to_string(nums[i]);
                hd_pos = i;
            }
            
            if (i+1 == nums.size() || nums[i+1] != nums[i]+1)
            {
                if(hd_pos == i)
                {
                    slist.push_back(s);
                    s = "";
                } else
                {
                    s = s + "->" + to_string(nums[i]);
                    slist.push_back(s);
                    s = "";
                }
                hd_pos = -1;
            }
            
        }
        
        return slist;
    }
};