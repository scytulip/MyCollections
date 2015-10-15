class Solution {
public:
    int myAtoi(string str) {
        int pos = 0;
        int len = str.size();
        long num = 0;
        bool sign = true;
        
        while(str[pos]==' ' && pos<len) pos ++;
        if (pos==len) return 0;
        if (str[pos] == '-')
        {
            sign = false;
            pos ++;
        } else if (str[pos] == '+')
            pos ++;
        else if (str[pos]>'9' || str[pos]<'0')
            return 0;
            
        while (str[pos]>='0' && str[pos]<='9' && 
            pos<len)
        {
            num *= 10;
            num += str[pos]-'0';
            if (sign && num>2147483647)
                return 2147483647;
            if (!sign && num>2147483648)
                return -2147483648;
            pos ++;
        }
        
        return (sign) ? num : (-num);
    }
};