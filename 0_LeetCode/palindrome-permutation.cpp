/*
266. Palindrome Permutation My Submissions QuestionEditorial Solution
Total Accepted: 13642 Total Submissions: 26636 Difficulty: Easy
Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.

Hint:

Consider the palindromes of odd vs even length. What difference do you notice?
Count the frequency of each character.
If each character occurs even number of times, then it must be a palindrome. How about character which occurs odd number of times?
*/
class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> ch_count(256, 0);
        
        for (auto& c : s) ++ch_count[c];
        
        int odd = 0;
        for (auto& i : ch_count) if (i%2==1) ++odd;
        
        if ((s.size()%2==0 && odd==0) ||
            (s.size()%2==1 && odd==1))
            return true;
        else
            return false;
    }
};