class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> fmap;
        unordered_map<char, char> rmap;
        int i;
        
        for (i=0; i<s.size(); i++)
        {
            if (rmap.find(t[i]) != rmap.end() &&
                rmap[t[i]] != s[i]) return false;
            if (fmap.find(s[i]) != fmap.end() &&
                fmap[s[i]] != t[i]) return false;
                    
            if (fmap.find(s[i])==fmap.end()) fmap[s[i]] = t[i];
            if (rmap.find(t[i])==rmap.end()) rmap[t[i]] = s[i];
        }
        
        return true;
    }
};