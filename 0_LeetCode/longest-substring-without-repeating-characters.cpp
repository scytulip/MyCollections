class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int len, max_len, left, i;
        unordered_set<char> cset;
        
        if (n==0) return 0;
        
        cset.insert(s[0]);
        len = 1;
        max_len = 1;
        left = 0;
        
        for (i=1; i<n; i++)
        {
            while (cset.count(s[i]))
            {
                cset.erase(s[left]);
                left ++;
                len --;
            }
            cset.insert(s[i]);
            len ++;
            if (len>max_len) max_len = len;
        }
        
        return max_len;
    }
};