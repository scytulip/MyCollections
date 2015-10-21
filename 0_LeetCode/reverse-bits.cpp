class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rt_val = 0;
        int i;
        
        for (i=0; i<32; i++)
        {
            rt_val = (rt_val << 1) | (n & 0x1);
            n = (n >> 1);
        }
        
        return rt_val;
    }
};