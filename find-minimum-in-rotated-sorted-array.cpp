class Solution {
public:
    int findMin(vector<int> &num) {
        
        vector<int>::iterator i;
        int min_val = *(num.begin());
        
        for (i=num.begin()+1; i!=num.end(); i++)
        {
            if (*i < min_val) min_val = *i;
        }
        
        return min_val;
    }
};