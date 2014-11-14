class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int i,j,len;
        unordered_map<int,int> hasht;
        vector<int> rt_val;
        
        len = numbers.size();
        for (i=0; i<len; i++)
        {
            if (hasht.find(numbers[i])==hasht.end())
                hasht.insert(pair<int,int>(target-numbers[i],i));
            else
            {
                rt_val.push_back(hasht[numbers[i]]+1);
                rt_val.push_back(i+1);
                return rt_val;
            }
        }
    }
};