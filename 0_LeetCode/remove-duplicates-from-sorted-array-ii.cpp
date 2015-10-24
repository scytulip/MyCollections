class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count;
        int i;
        int n = nums.size();
        int len = 2;
        
        if (n==0)
            return 0;
        else if (n==1)
            return 1;
        else if (n==2)
            return 2;
        
        vector<int>::iterator it;
        it = nums.begin();
        it ++; it ++; i = 2;
        while(it != nums.end())
        {
            if ((*it)==(*(it-1)) && (*it)==(*(it-2))) 
            {
                nums.erase(it);
                it = nums.begin()+i;
            } else
            {
                it ++; i ++;
            }
        }
        
        return i;
    }
};