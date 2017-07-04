class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> ch_count(256, 0);
        for (const auto& c : magazine) ++ ch_count[c];
        for (const auto& c : ransomNote) {
            if (ch_count[c]==0)
                return false;
            else
                -- ch_count[c];
        }
        return true;
    }
};