/*
370. Range Addition  QuestionEditorial Solution  My Submissions
Total Accepted: 1140
Total Submissions: 2276
Difficulty: Medium
Assume you have an array of length n initialized with all 0's and are given k update operations.

Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.

Return the modified array after all k operations were executed.

Example:

Given:

    length = 5,
    updates = [
        [1,  3,  2],
        [2,  4,  3],
        [0,  2, -2]
    ]

Output:

    [-2, 0, 3, 5, 3]
Explanation:

Initial state:
[ 0, 0, 0, 0, 0 ]

After applying operation [1, 3, 2]:
[ 0, 2, 2, 2, 0 ]

After applying operation [2, 4, 3]:
[ 0, 2, 5, 5, 3 ]

After applying operation [0, 2, -2]:
[-2, 0, 3, 5, 3 ]
Hint:

Thinking of using advanced data structures? You are thinking it too complicated.
For each update operation, do you really need to update all elements between i and j?
Update only the first and end element is sufficient.
The optimal time complexity is O(k + n) and uses O(1) extra space.
*/

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> mod(length, 0);
        
        sort(updates.begin(), updates.end(),
            [](const vector<int>& a, const vector<int>& b) {return a[0]<b[0];});
        
        int val = 0;
        vector<vector<int>>::iterator iter = updates.begin();
        for (int i=0; i<length; ++i) {
            while (iter!=updates.end() && (*iter)[0]<=i) {
                val += (*iter)[2];
                ++ iter;
            }
            mod[i] = val;
        }
        
        sort(updates.begin(), updates.end(),
            [](const vector<int>& a, const vector<int>& b) {return a[1]<b[1];});
            
        val = 0;
        iter = updates.begin();
        for (int i=0; i<length; ++i) {
            while (iter!=updates.end() && (*iter)[1]<i) {
                val += (*iter)[2];
                ++ iter;
            }
            mod[i] -= val;
        }
        
        return mod;
    }
};