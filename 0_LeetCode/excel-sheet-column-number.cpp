class Solution {
public:
    int titleToNumber(string s) {
        int col = 0;
        int i;
        
        for (i=0; i<s.size(); i++)
        {
            col *= 26;
            col += (s[i]-'A')+1;
        }
        
        return col;
    }
};