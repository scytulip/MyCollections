/*
267. Palindrome Permutation II My Submissions QuestionEditorial Solution
Total Accepted: 5917 Total Submissions: 20916 Difficulty: Medium
Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

For example:

Given s = "aabb", return ["abba", "baab"].

Given s = "abc", return [].

Hint:

If a palindromic permutation exists, we just need to generate the first half of the string.
To generate all distinct permutations of a (half of) string, use a similar approach from: Permutations II or Next Permutation.
*/

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<int> ch_count(256, 0);
        
        len = s.size();
        pstr = s;
        for (auto& c : s) ++ch_count[c];
        
        int odd = 0;
        for (int i=0; i<256; ++i)
            if (ch_count[i]%2==1) {++odd; pstr[len/2]=(char)i;}
        
        if (!((s.size()%2==0 && odd==0) ||
            (s.size()%2==1 && odd==1)))
            return rec;
            
        search(ch_count, 0, 0);
        return rec;
    }

private:
    vector<string> rec;
    string pstr;
    int len;

    void search(vector<int>& ch_count, int start, int lvl) {
        if (lvl==len/2) {
            rec.push_back(pstr);
            return;
        }
        for (int i=0; i<256; ++i)
            if (ch_count[i]>=2) {
                ch_count[i] -= 2;
                pstr[lvl] = (char)i;
                pstr[len-lvl-1] = (char)i;
                search(ch_count, i, lvl+1);
                ch_count[i] += 2;
            }
    }
};