/*
277. Find the Celebrity  QuestionEditorial Solution  My Submissions
Total Accepted: 9683
Total Submissions: 27566
Difficulty: Medium
Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people know him/her but he/she does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" to get information of whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).

You are given a helper function bool knows(a, b) which tells you whether A knows B. Implement a function int findCelebrity(n), your function should minimize the number of calls to knows.

Note: There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party. If there is no celebrity, return -1.
*/

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        if (n==1) return -1;
        
        vector<bool> set(n, true);
        
        int count = n;
        int remain = 0;
        for (int i=0; i<n; ++i) {
            remain = i;
            for (int j=0; j<n; ++j)
                if (i!=j && set[j]) {
                    if (!knows(i,j)) {
                        set[j] = false; 
                        --count;
                    } else {
                        remain = j;
                    }
                }
            if (count<=1) break;
        }
        
        if (count!=1) return -1;
        
        for (int i=0; i<n; ++i)
            if (i!=remain) {
                if (!knows(i, remain)) return -1;
                if (knows(remain, i)) return -1;
            }
        return remain;
    }
};