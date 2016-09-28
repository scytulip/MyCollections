class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> list;
        if (s.size()<=10) return list;
        
        unordered_map<long, int> nset;
        long dna_seq = 0;
        for (int i=0; i<s.size(); ++i) {
            dna_seq = (dna_seq<<2) & 0xFFFFF;
            switch(s[i]) {
                case 'A' : dna_seq |= 0; break;
                case 'C' : dna_seq |= 1; break;
                case 'G' : dna_seq |= 2; break;
                case 'T' : dna_seq |= 3; break;
            }
            if (i>=9) {
                if (nset[dna_seq]==1) list.push_back(s.substr(i-9, 10));
                nset[dna_seq]++;
            }
        }
        return list;
    }
};