/*
254. Factor Combinations My Submissions QuestionEditorial Solution
Total Accepted: 9110 Total Submissions: 25739 Difficulty: Medium
Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note: 
You may assume that n is always positive.
Factors should be greater than 1 and less than n.
Examples: 
input: 1
output: 
[]
input: 37
output: 
[]
input: 12
output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
input: 32
output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
*/

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        search(n,2);
        return list;
    }
private:
    vector<vector<int>> list;
    vector<int> track;
    void search(int n, int k) {
        if (n==1) {
            if (track.size()>1) list.push_back(track);
            return;
        }
        
        for (int i=k; i<=sqrt(n); ++i)
            if (n%i==0) {
                track.push_back(i);
                search(n/i, i);
                track.pop_back();
            }
        
        track.push_back(n);
        search(1,2);
        track.pop_back();
    }
};