/*
345. Reverse Vowels of a String My Submissions QuestionEditorial Solution
Total Accepted: 24544 Total Submissions: 68807 Difficulty: Easy
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".
*/

class Solution {
public:
    string reverseVowels(string s) {
        stack<char> vowels;
        queue<int> pos;
        
        char c;
        for (int i=0; i<s.size(); ++i) {
            c = s[i];
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
                c=='A' || c=='E' || c=='I' || c=='O' || c=='U') {
                vowels.push(c);
                pos.push(i);
            }
        }
        
        string res = s;
        while (!pos.empty()) {
            res[pos.front()] = vowels.top();
            vowels.pop();
            pos.pop();
        }
        
        return res;
    }
};