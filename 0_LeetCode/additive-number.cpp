class Solution {
public:
    bool isAdditiveNumber(string num) {
        int len = num.size();
        if (len < 3) return false;
        
        for (int i = 1; i <= len/3*2; ++i) {
            for (int j = 0; j <= i-1; ++j) {
                if (num[0] == '0' && j >= 1) continue;
                if (num[j+1] == '0' && j != i-1) continue;
                if (VerifySeq(num, GetNum(num, 0, j), GetNum(num, j+1, i), i+1)) return true;
            }
        }
        
        return false;
    }
private:
    long GetNum(const string& num, int start, int end) {
        long val = 0;
        for (int i = start; i <= end; ++i) {
            val *= 10;
            val += num[i]-'0';
        }
        return val;
    }
    bool VerifySeq(const string& num, long num1, long num2, int start) {
        string new_str;
        long sum;
        if (start == num.size()) return false;
        while(start < num.size()) {
            sum = num1+num2;
            new_str = to_string(sum);
            if (start == num.size()) return false;
            if (start + new_str.size() > num.size()) return false;
            for (const char& c : new_str) {
                if (num[start] != c) return false;
                ++ start;
            }
            num1 = num2;
            num2 = sum;
        }
        return true;
    }
};