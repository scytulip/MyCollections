class Solution {
public:
    string simplifyPath(string path) {
        
        int start, slen;
        int len;
        int i;
        string pth = path;
        string str;
        stack<string> pth_stk;
        
        if (*(pth.begin())!='/') pth = "/"+pth;
        if (*(pth.end()-1)!='/') pth = pth + "/";
        
        len = pth.size();
        start = 1; slen = 0;
        
        for (i=1; i<len; i++)
        {
            if (pth[i]!='/')
                slen ++;
            else
            {
                if (slen != 0)
                {
                    str = pth.substr(start,slen);
                    if (str != ".")
                    {
                        if (str != "..") // Judge .., but ... is a folder name
                            pth_stk.push(str);
                        else if (!pth_stk.empty()) // Pop empty stack --> error
                            pth_stk.pop();
                            
                    }
                }
                start = i + 1;
                slen = 0;
            }
        }
        
        if (pth_stk.empty()) return "/";
        
        pth = "";
        while (!pth_stk.empty())
        {
            pth = "/" + pth_stk.top() + pth; // Attention: order is reversed
            pth_stk.pop();
        }
        return pth;
    }
};