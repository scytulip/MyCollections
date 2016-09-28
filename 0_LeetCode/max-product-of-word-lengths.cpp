class Solution {
public:
    int maxProduct(vector<string>& words) {
        // Char set
        vector<long> cset;
        vector<int> sz;
        long mark;
        for (auto str : words) {
            mark = 0;
            for (auto ch : str) mark |= (0x1 << (ch-'a'));
            cset.push_back(mark);
            sz.push_back(str.size());
        }
        
        // Find max
        int max = 0;
        int len = words.size();
        int val;
        for (int i=0; i<len; ++i) {
            for (int j=i; j<len; ++j) {
                val = (cset[i]&cset[j]) ? 0 : (sz[i]*sz[j]);
                max = (val>max) ? val : max;
            }
        }
        
        return max;
    }
};