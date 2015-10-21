class Solution {
public:
    int compareVersion(string version1, string version2) {
        queue<int> v1;
        queue<int> v2;
        
        int i;
        int ver = 0;
        
        // Convert to queue
        i = 0;
        while (i<version1.size())
        {
            if (version1[i] != '.')
            {
                ver *= 10;
                ver += version1[i]-'0';
            } else
            {
                v1.push(ver);
                ver = 0;
            }
            i ++;
        }
        v1.push(ver);
        ver = 0;
        
        i = 0;
        while (i<version2.size())
        {
            if (version2[i] != '.')
            {
                ver *= 10;
                ver += version2[i]-'0';
            } else
            {
                v2.push(ver);
                ver = 0;
            }
            i ++;
        }
        v2.push(ver);
        ver = 0;
        
        // Compare
        int a, b;
        while (!v1.empty() || !v2.empty())
        {
            a = (v1.empty()) ? 0 : v1.front();
            b = (v2.empty()) ? 0 : v2.front();
            if (a>b)
                return 1;
            else if (a<b)
                return -1;
            if (!v1.empty()) v1.pop();
            if (!v2.empty()) v2.pop();
        }
        
        return 0;
    }
};