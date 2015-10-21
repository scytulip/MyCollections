class Solution {
public:
    int lengthOfLastWord(string s) {
        string::reverse_iterator it;
        string str = s;
        
        it = str.rbegin();
        
        /* Trim tail spaces */
        while (it != str.rend())
        {
            if (*it != ' ') break;
            it ++;
        }
        
        str.erase(it.base(), str.end());
        
        /* Count */
        if (str.empty()) return 0;
        
        int count = 0;
        
        it = str.rbegin();
        
        while(it != str.rend())
        {
            if (*it == ' ') break;
            count ++;
            it ++;
        }
        
        return count;
    }
};