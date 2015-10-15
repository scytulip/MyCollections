class Solution {
public:
    bool isValid(string s) {
        int i;
        stack<char> pr;
        
        if (s.size()==0) return true;
        
        for (i=0; i<s.size(); i++)
        {
            switch(s[i])
            {
                case '(':
                case '[':
                case '{':
                    pr.push(s[i]);
                    break;
                case ')':
                    if (pr.size()==0 || pr.top()!='(') return false;
                    pr.pop();
                    break;
                case ']':
                    if (pr.size()==0 || pr.top()!='[') return false;
                    pr.pop();
                    break;
                case '}':
                    if (pr.size()==0 || pr.top()!='{') return false;
                    pr.pop();
                    break;
            }
        }
        
        return (pr.size() == 0);
    }
};