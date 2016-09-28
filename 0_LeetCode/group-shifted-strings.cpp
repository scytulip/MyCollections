/*
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
A solution is:

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
*/

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> list;
        if (strings.empty()) return list;
        list.push_back(vector<string>(1, strings[0]));
        
        bool mark;
        for (int i=1; i<strings.size(); ++i) {
            mark = false;
            for (auto& vec:list) { // ATTEN: auto& here
                if (inSameSeq(vec[0], strings[i])) {
                    vec.push_back(strings[i]);
                    mark = true;
                    break;
                }
            }
            if (!mark) list.push_back(vector<string>(1, strings[i]));
        }
        
        return list;
    }
private:
    bool inSameSeq(const string& w1, const string& w2) {
        if (w1.size()!=w2.size()) return false;
        if (w1=="" && w2=="") return true;
        int diff = (w1[0]-w2[0]+26)%26;
        for(int i=1; i<w1.size(); ++i) if(((w1[i]-w2[i]+26)%26)!=diff) return false;
        return true;
    }
};