class Solution {
private:
    vector<string> list;
    vector<string> rec;
    void cut(string s, int lvl)
    {
        int i,n;
        string str;
        
        if (lvl==0)
        {
            if ((s.size()>3) || (stoi(s)>255)) return;
            if (s.size()>1 && s[0]=='0') return;
            for (i=0; i<3; i++) str += rec[i]+'.';
            str += s;
            list.push_back(str);
            return;
        }
        
        n = s.size();
        for (i=1; i<=3; i++)
        {
            str = s.substr(0,i);
            if ((n-i<=0) || (i==3 && stoi(str)>255)) return;
            if (i>1 && str[0]=='0') return;
            rec.push_back(str);
            cut(s.substr(i,n-i), lvl-1);
            rec.pop_back();
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        cut(s, 3);
        return list;
    }
};