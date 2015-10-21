class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        int hd = 0;
        int i,a,b,tmp,idx;
        
        if (len>1)
            for (i=1; i<len; i++)
            {
                if (nums[i]<nums[i-1])
                {
                    hd = i; break;
                }
            }
        
        a = 0;
        b = len-1;
        tmp = (a+b)/2;
        while (b-a>1)
        {
            tmp = (a+b)/2;
            idx = (tmp+hd) % len;
            if (nums[idx]<target)
                a = tmp;
            else
                b = tmp;
        }
        
        return (nums[(a+hd)%len]==target || nums[(b+hd)%len]==target);
    }
};