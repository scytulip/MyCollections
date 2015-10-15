class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lc_str = "";
        char cand;
        int i;
        int idx = 0;
        
        if (0 == strs.size()) return "";
        
        /* check all strings */
        while(1)
        {
            for (i=0; i<strs.size(); i++)
            {
                if (idx >= strs[i].size()) return lc_str;
                if (0 == i)
                {
                    cand = strs[i][idx];
                } else
                {
                    if (cand != strs[i][idx]) return lc_str;
                }
            }
            idx ++;
            lc_str += cand;
        }
    }
};