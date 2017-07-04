/*
186. Reverse Words in a String II My Submissions QuestionEditorial Solution
Total Accepted: 10967 Total Submissions: 37815 Difficulty: Medium
Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?

Related problem: Rotate Array
*/

class Solution {
public:
    void reverseWords(string &s) {
        reverseSeq(s, 0, s.size());
        
        int start = 0;
        int end = 0;
        while (end<s.size()) {
            while (end<s.size() && s[end]!=' ') ++end;
            reverseSeq(s, start, end);
            start = (++end);
        }
    }
private:
    void reverseSeq(string& s, int start, int end) {
        char c;
        --end;
        while (start<end) {
            c = s[start];
            s[start] = s[end];
            s[end] = c;
            ++ start;
            -- end;
        }
    }
};