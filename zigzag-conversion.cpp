class Solution {
public:
    string convert(string s, int numRows) {
        int i;
        int idx;
        int len = s.size();
        string str;
        
        if (numRows == 1) return s;
        
        for (i=0; i<numRows; i++)
        {
            idx = i;
            while (idx < len)
            {
                str += s[idx];
                if ((i!=0 && i!=numRows-1) && 
                    (2*numRows-2-2*i+idx<len))
                    str += s[2*numRows-2-2*i+idx];
                idx += 2*numRows-2;
            }
        }
        
        return str;
    }
};