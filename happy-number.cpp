class Solution {
public:
    bool isHappy(int n) {
        int num = n;
        int val = 0;
        unordered_set<int> myset;
        
        myset.insert(n);
        
        while (num != 1)
        {
            val = 0;
            while(num != 0)
            {
                val += (num % 10)*(num % 10);
                num /= 10;
            }
            num = val;
            
            if (myset.find(num) != myset.end())
                break;
            else
                myset.insert(num);
        } 
        
        if (num == 1) return true; else return false;
    }
};