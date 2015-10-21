/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> rt_val, tmp;
        vector<string>::iterator i;
        string::iterator j;
        int k;
        
        int len;        // Length of the char list
        char ld;        // Leading character of the char list
        
        rt_val.insert(rt_val.begin(),"");
        
        for (j=digits.begin(); j!=digits.end(); j++)
        {
            switch (*j)
            {
                case '2': len = 3; ld = 'a'; break;
                case '3': len = 3; ld = 'd'; break;
                case '4': len = 3; ld = 'g'; break;
                case '5': len = 3; ld = 'j'; break;
                case '6': len = 3; ld = 'm'; break;
                case '7': len = 4; ld = 'p'; break;
                case '8': len = 3; ld = 't'; break;
                case '9': len = 4; ld = 'w'; break;
            }
            
            if (*j!='1')
            {
                tmp.clear();
                for (i=rt_val.begin(); i!=rt_val.end(); i++)
                {
                    for(k=0; k<len; k++)
                    {
                        tmp.insert(tmp.begin(),(*i)+char(ld+k)); // Add char to string tail
                    }
                }
                rt_val.clear();
                rt_val = tmp;
            }
            
        }
        
        return rt_val;
    }
};