class Solution {
private:
    struct mycomp_stut{
        bool operator()(string a, string b)
        {
            string x = a+b;
            string y = b+a;
            return x>y;
        }
    } mycomp;
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (int i=0; i<nums.size(); i++) strs.push_back(to_string(nums[i]));
        sort(strs.begin(), strs.end(), mycomp);

        string out;
        for (vector<string>::iterator i=strs.begin(); i!=strs.end(); i++) out += (*i);
        
        int i = 0;
        while(out[i]=='0' && i<out.size()-1) i++;
        out = out.substr(i,out.size()-i);
        
        return out;
    }
};