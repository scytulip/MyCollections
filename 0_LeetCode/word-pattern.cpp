class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string, char> wmap;
        unordered_map<char, string> pmap;
        string word;
        istringstream iss(str);
        int i;
        
        for (i=0; i<pattern.size(); i++)
        {
            if (!iss) return false;
            
            iss >> word; // split by spaces
            
            if (wmap.find(word) != wmap.end() &&
                wmap[word] != pattern[i]) return false;
            if (pmap.find(pattern[i]) != pmap.end() &&
                pmap[pattern[i]] != word) return false;
                
            if (wmap.find(word) == wmap.end()) wmap[word] = pattern[i];
            if (pmap.find(pattern[i]) == pmap.end()) pmap[pattern[i]] = word;
        }
        
        iss >> word;
        return (iss.fail()) ? true : false;
    }
};