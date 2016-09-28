class Solution {
public:
    string getHint(string secret, string guess) {
        int hit[10] = {0};
        
        int ct_a = 0;
        for (int i=0; i<secret.length(); ++i) {
            if (secret[i]==guess[i]) {
                ++ ct_a;
            } else {
                ++ hit[secret[i]-'0'];
                -- hit[guess[i]-'0'];
            }
        }
        
        int ct_b = 0;
        for (int i=0; i<10; ++i) {
            ct_b += abs(hit[i]);
        }
        ct_b = secret.length()-ct_a-ct_b/2;
        
        std::stringstream buffer;
        buffer << ct_a << 'A' << ct_b << 'B';
        
        return buffer.str();
    }
};