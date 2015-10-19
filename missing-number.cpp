
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long x = 0;
        int i;
        int n = nums.size();
        
        for (i=0; i<n+1; i++) x += i;
        for (i=0; i<n; i++) x -= nums[i];
        
        return x;
    }
};