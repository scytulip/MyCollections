#include <iostream>
#include <unordered_set>
#include <string>
#include <limits.h>

using namespace std;

class Solution {
private:
    bool isOnlyOneChg(const string& a, const string& b)
    {
        int i,j;
        j = 0;
        for (i=0; i<a.size(); i++)
        {
            if (a[i]!=b[i]) j++;
            if (j>1) return false;
        }
        return (j==1);
    }
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {

        unordered_set<string>::iterator it, jt;
        int i,j;
        wordList.erase(beginWord);
        wordList.erase(endWord);

        if (isOnlyOneChg(beginWord, endWord)) return 1;

        // Pre-process
        int len = wordList.size();
        bool graph[len+2][len+2]; // [x][y] direction from x to y

        for (i=0; i<len+2; i++)
            for (j=0; j<len+2; j++)
                graph[i][j] = false;

        it = wordList.begin();
        for (i=0; i<len; i++)
        {
            jt = it;
            for (j=i+1; j<len; j++)
            {
                jt++;
                if (it!=jt && isOnlyOneChg(*it, *jt))
                {
                    graph[i][j] = true;
                    graph[j][i] = true;
                }
            }
            it ++;
        }

        it = wordList.begin(); j = 0;
        for (i=0; i<len; i++)
        {
            if (isOnlyOneChg(beginWord, *it))
            {
                graph[len][i] = true;
            }
            if (isOnlyOneChg(endWord, *it))
            {
                graph[i][len+1] = true;
                j ++;
            }
            it ++;
        }

        if (j==0) return 0;

        // Compute the shortest path, BFS
        int rec[len];

        for (i=0; i<len; i++)
            if (graph[len][i]) rec[i] = 1; else rec[i] = INT_MAX;

        bool changed = true;
        int stpath = INT_MAX;

        while(changed)
        {
            changed = false;
            stpath = INT_MAX;
            for (i=0; i<len; i++)
            {
                if (graph[i][len+1] && rec[i]!=INT_MAX && rec[i]+1<stpath) //!!INT_MAX
                {
                    stpath = rec[i]+1;
                }
                for (j=0; j<len; j++)
                {
                    if (graph[i][j] && rec[i]!=INT_MAX && rec[i]+1<rec[j]) //!!INT_MAX
                    {
                        changed = true;
                        rec[j] = rec[i]+1;
                    }
                }
            }
            if (stpath!=INT_MAX) break;
        }

        // Return
        if (stpath!=INT_MAX)
            return stpath+1;
        else
            return 0;
    }
};

int main()
{
    Solution sol;

    unordered_set<string> slist;
    slist.insert("a");
    slist.insert("b");
    slist.insert("c");
    //slist.insert("dot");
    //slist.insert("lot");

    cout << sol.ladderLength("a", "b", slist) << endl;

    return 0;
}
