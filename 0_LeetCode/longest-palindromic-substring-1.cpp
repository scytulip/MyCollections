class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        int left = 0;
        int right = 0;
        int m_left = 0; 
        int m_right = 0;
        
        while (left<(len-(m_right-m_left))) {
            right = left + (m_right-m_left) + 1;
            while (right<len) {
                while (s[left]!=s[right] && right<len) right++;
                if (right==len) break;
                if (isPalindromic(s, left, right)) {
                    m_left = left;
                    m_right = right;
                }
                right ++;
            }
            left ++;
        }
        
        return s.substr(m_left, m_right-m_left+1);
    }
    
private:
    bool isPalindromic(const string& s, int left, int right) {
        while (left<right) {
            if (s[left]!=s[right]) return false;
            left ++;
            right --;
        }
        return true;
    }
};