class Solution {
public:
    int nthUglyNumber(int n) {
        if (n==1) return 1;
        
        int count = 1;
        int cur_val = 0;
        int v2, v3, v5;
        queue<int> m2; m2.push(2);
        queue<int> m3; m3.push(3);
        queue<int> m5; m5.push(5);

        while (count<n) {
            v2 = m2.empty() ? INT_MAX : m2.front();
            v3 = m3.empty() ? INT_MAX : m3.front();
            v5 = m5.empty() ? INT_MAX : m5.front();
            if (v2<=v3 && v2<=v5) m2.pop();
            else if (v3<=v2 && v3<=v5) {m3.pop(); v2=v3;}
            else if (v5<=v2 && v5<=v3) {m5.pop(); v2=v5;}
            
            if (v2 != cur_val) {
                ++count;
                cur_val = v2;
                m2.push(cur_val*2);
                m3.push(cur_val*3);
                m5.push(cur_val*5);
            }
        }
        
        return cur_val;
    }
};