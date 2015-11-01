// A better solution
// https://leetcode.com/discuss/62695/o-n-solution-in-java-with-two-simple-pass-in-the-array

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i,j;
        int n = nums.size();
        int max = INT_MIN;
        int max_ct = 0;
        vector<int> rec;
        
        if (nums.size()==0) return rec;
        
        for (i=0; i<k; i++) 
            if (nums[i]>max)
            {
                max = nums[i];
                max_ct = 1;
            } else if (nums[i]==max)
            {
                max_ct ++;
            }
            
        rec.push_back(max);
            
        for (j=k; j<n; j++)
        {
            if (nums[j-k]==max)
            {
                max_ct --;
            }
            if (max_ct==0)
            {
                max = INT_MIN;
                for (i=j-k+1; i<=j; i++)
                    if (nums[i]>max)
                    {
                        max = nums[i];
                        max_ct = 1;
                    } else if (nums[i]==max)
                    {
                        max_ct ++;
                    }
            } else if (nums[j]>max)
            {
                max = nums[j];
                max_ct = 1;
            } else if (nums[j]==max)
            {
                max_ct ++;
            }
            
            rec.push_back(max);
        }
        
        return (rec);
    }
};