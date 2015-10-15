class Solution {
public:
    string countAndSay(int n) {
        string val;
        string valnew;
        int i,j,count;
        
        if (n==1) return "1";
        
        val = "1";
        count = 1;
        
        for (i=1; i<n; i++)
        {
            valnew = "";
            val = val + '0';
            for (j=0; j<val.size()-1; j++)
            {
                if (val[j]!=val[j+1])
                {
                    valnew += to_string(count) + val[j];
                    count = 1;
                } else
                    count ++;
            }
            val = valnew;
        }
        
        return val;
    }
};