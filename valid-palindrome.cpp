class Solution {
public:
    bool isPalindrome(string s) {
        int i;
        int a, b;
        
        if (s.empty()) return true;
        
        for (i=0; i<s.size(); i++)
        {
            if (s[i] <= 'Z' && s[i] >= 'A')
                s[i] = s[i] - 'A' + 'a';
        }
        
        a = 0; b = s.size()-1;
        
        while(a<b)
        {
            while ((s[a]<'a' || s[a]>'z') && (s[a]<'0' || s[a]>'9') && (a<b)) a++;
            while ((s[b]<'a' || s[b]>'z') && (s[b]<'0' || s[b]>'9') && (a<b)) b--;
            if (s[a] != s[b]) return false;
            a++; b--;
        }
        
        return true;
    }
};