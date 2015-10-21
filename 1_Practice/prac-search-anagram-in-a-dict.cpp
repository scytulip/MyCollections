#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

/// Anagram Set
/// http://www.themianjing.com/2015/06/uber-%E7%94%B5%E9%9D%A2%E9%9D%A2%E7%BB%8F/

class Solution {
private:
    struct hash_ky {
        size_t operator() (const vector<int>& x) const
        {
            int i;
            int key = 0;
            for (i=0; i<x.size(); i++) key+=x[i];
            return hash<int>()(key);
        }
    };
    struct vec_eq {
        bool operator() (const vector<int>& x, const vector<int>& y) const
        {
            int i;
            for (i=0; i<x.size(); i++)
            {
                if (x[i]!=y[i]) return false;
            }
            return true;
        }
    };

public:
    bool isAnagramExisted(string word, unordered_set<string> dict)
    {
        unordered_set<string>::iterator it;
        unordered_set<vector<int>, hash_ky, vec_eq> mydict;
        vector<int> ana_set(26,0);
        int i;
        string s;

        for (it=dict.begin(); it!=dict.end(); it++)
        {
            for (i=0; i<26; i++) ana_set[i]=0;
            s = *it;
            for (i=0; i<s.size(); i++) ana_set[s[i]-'a'] ++;
            mydict.insert(ana_set);
        }

        for (i=0; i<26; i++) ana_set[i]=0;
        for (i=0; i<word.size(); i++) ana_set[word[i]-'a'] ++;

        return mydict.count(ana_set);
    }
};

int main()
{
    unordered_set<string> dict;
    dict.insert("abcdefg");
    dict.insert("analog");
    dict.insert("dogdog");
    dict.insert("godgod");
    dict.insert("anagram");

    Solution sol;
    cout << sol.isAnagramExisted("doogg", dict) << endl;
    cout << sol.isAnagramExisted("gfedcab", dict) << endl;
    cout << sol.isAnagramExisted("ddoogg", dict) << endl;

    return 0;
}
