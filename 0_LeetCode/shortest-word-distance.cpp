/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int len = words.size();
        vector<int> before = vector<int>(len, 0);
        vector<int> after = vector<int>(len, 0);
        
        int prv;
        prv = -1;
        for (int i=0; i<words.size(); ++i) { if (word1==words[i]) prv = i; before[i] = prv;  }
        prv = -1;
        for (int i=words.size()-1; i>=0; --i) { if (word1==words[i]) prv = i; after[i] = prv; }
        
        int min = INT_MAX;
        for (int i=0; i<words.size(); ++i) {
            if (words[i]==word2) {
                if (before[i]!=-1 && i-before[i]<min) min = i-before[i];
                if (after[i]!=-1 && after[i]-i<min) min = after[i]-i;
            }
        }
        
        return min;
    }
};