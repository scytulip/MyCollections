class Solution {
private:
    vector<char> opr;
    vector<int> num;
    
    vector<int> search(int a, int b)
    {
        int i;
        vector<int> left, right, rtv;
        vector<int>::iterator j,k;
        
        if (a==b) {rtv.push_back(num[a]); return rtv;}
        
        for (i=a; i<b; i++)
        {
            left = search(a,i);
            right = search(i+1,b);
            for (j=left.begin(); j!=left.end(); j++)
                for (k=right.begin(); k!=right.end(); k++)
                {
                    switch(opr[i])
                    {
                        case '-': rtv.push_back((*j)-(*k)); break;
                        case '+': rtv.push_back((*j)+(*k)); break;
                        case '*': rtv.push_back((*j)*(*k)); break;
                    }
                }
        }
        
        return rtv;
    }
public:
    vector<int> diffWaysToCompute(string input) {

        /* Parse */
        int i;
        int val=0;
        for (i=0; i<input.size(); i++) 
        {
            if (input[i]<='9' && input[i]>='0') 
            {
                val *= 10;
                val += (input[i]-'0');
            } else
            {
                num.push_back(val);
                opr.push_back(input[i]);
                val = 0;
            }
        }
        num.push_back(val);
        
        return search(0,opr.size());

    }
};