class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int i, n=0, kmax=INT_MIN;
        vector<int> line;
        vector<int>::iterator it;
        
        for (i=0; i<nums.size(); i++)
        {
            if (nums[i]>kmax)
            {
                it = line.begin();
                while(it!=line.end() && (*it)>nums[i]) it++;
                line.insert(it, nums[i]);
                n ++;
                if (n>k)
                {
                    n = k;
                    line.pop_back();
                    kmax = *(line.rbegin());
                }
            }
        }
        
        kmax = *(line.rbegin());
        return kmax;
    }
};