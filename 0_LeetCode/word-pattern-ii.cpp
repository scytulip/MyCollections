/*
291. Word Pattern II  QuestionEditorial Solution  My Submissions
Total Accepted: 6227
Total Submissions: 17487
Difficulty: Hard
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Examples:
pattern = "abab", str = "redblueredblue" should return true.
pattern = "aaaa", str = "asdasdasdasd" should return true.
pattern = "aabb", str = "xyzabcxzyabc" should return false.
Notes:
You may assume both pattern and str contains only lowercase letters.
*/

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        if (pattern.empty() && str.empty()) return true;
        if (!pattern.empty() && str.empty()) return false;
        map = vector<string>(26, "");
        return search(pattern, str, 0, 0);
    }
private:
    vector<string> map;
    bool search(const string& pattern, const string& str, int pp, int ps) {
        if (pp==pattern.size() && ps==str.size()) return true;
        if (pp>=pattern.size() || ps>=str.size()) return false;
        
        string& s = map[pattern[pp]-'a'];
        if (s!="") {
            if (s == str.substr(ps, s.size())) {
                return search(pattern, str, pp+1, ps+s.size());
            } else {
                return false;
            }
        } else {
            for (int i=ps; i<str.size(); ++i) {
               s.append(1, str[i]);
               bool skip = false;
               for (char j='a'; j<='z'; ++j) {
                   if (j!=pattern[pp] && s==map[j-'a']) {
                       skip = true; break;
                   }
               }
               if (skip) continue;
               if (search(pattern, str, pp+1, i+1)) return true;
            }
            s = "";
            return false;
        }
    }
};