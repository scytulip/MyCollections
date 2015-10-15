class Solution {
public:
    bool isAnagram(string s, string t) {
        int wd[26] = {0};
        int len = s.size();
        int i;
        
        if (len != t.size()) return false;
        
        for (i=0; i<len; i++)
        {
            wd[s[i]-'a'] ++;
            wd[t[i]-'a'] --;
        }
        
        for (i=0; i<26; i++)
        {
            if (wd[i] != 0) return false;
        }
        
        return true;
    }
};