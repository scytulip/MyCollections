class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int i,v;
        vector<int> ct(n+1,0);
        
        if (n==0) return 0;
        
        if (s[0]!='0') ct[0] = 1;
        if (n==1) return ct[0];
        
        if (s[1]!='0') ct[1] += ct[0];
        v = (s[0]-'0')*10+(s[1]-'0');
        if (s[0]!='0' && v<=26 && v>0) ct[1] ++;
        
        for (i=2; i<n; i++)
        {
            if (s[i]!='0') ct[i] += ct[i-1];
            v = (s[i-1]-'0')*10+(s[i]-'0');
            if (s[i-1]!='0' && v<=26 && v>0) ct[i] += ct[i-2];
        }
        
        return ct[n-1];
    }
};