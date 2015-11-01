class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dict;

        int i;
        string s;
        vector<string>::iterator it;
        for (it=strs.begin(); it!=strs.end(); it++)
        {
            s = (*it);
            sort(s.begin(), s.end());
            dict[s].push_back(*it);
        }
        
        unordered_map<string, vector<string>>::iterator jt;
        vector<vector<string>> list;
        for (jt=dict.begin(); jt!=dict.end(); jt++)
        {
            sort(jt->second.begin(), jt->second.end());
            list.push_back(jt->second);
        }
        
        return list;
        
    }
};