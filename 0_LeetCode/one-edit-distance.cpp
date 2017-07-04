/*
161. One Edit Distance My Submissions QuestionEditorial Solution
Total Accepted: 13466 Total Submissions: 46721 Difficulty: Medium
Given two strings S and T, determine if they are both one edit distance apart.
*/

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s==t) return false;
        
        if (s.size()>t.size()) {
            string x = s;
            s = t; t = x;
        }
        
        if (t.size()-s.size()>=2) 
            return false;
        else if (s.empty())
            return true;
        
        string::iterator head_s = s.begin();
        string::iterator tail_s = s.end()-1;
        string::iterator head_t = t.begin();
        string::iterator tail_t = t.end()-1;
        while (head_s != tail_s && (*head_t)==(*head_s)) {
            ++head_s; ++head_t;
        }
        while (head_s != tail_s && (*tail_t)==(*tail_s)) {
            --tail_s; --tail_t;
        }
        
        return (s.size()==t.size()) ? (tail_t==head_t) : 
            (tail_t-head_t==1 && ((*head_s)==(*tail_t)||(*head_s)==(*head_t))); // ATTETION!
    }
};