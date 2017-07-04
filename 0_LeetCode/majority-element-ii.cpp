class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = 0, num2 = 0;
        int ct1 = 0, ct2 = 0;
        
        for (const auto& i : nums) {
            if (i == num1)
                ++ ct1;
            else if (i == num2)
                ++ ct2;
            else if (ct1 == 0)
                num1 = i, ct1 = 1;
            else if (ct2 == 0)
                num2 = i, ct2 = 1;
            else
                -- ct1, -- ct2;
        }
        
        ct1 = ct2 = 0;
        for (const auto& i : nums) {
            if (i == num1) ++ ct1;
            else if (i == num2) ++ ct2;
        }
        
        vector<int> result;
        if (ct1 > nums.size()/3) result.push_back(num1);
        if (ct2 > nums.size()/3) result.push_back(num2);
        
        return result;
    }
};