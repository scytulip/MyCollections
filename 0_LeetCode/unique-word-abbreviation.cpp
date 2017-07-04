/*
288. Unique Word Abbreviation My Submissions QuestionEditorial Solution
Total Accepted: 10594 Total Submissions: 67215 Difficulty: Easy
An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
d) l|ocalizatio|n          --> l10n
Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Example: 
Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true
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