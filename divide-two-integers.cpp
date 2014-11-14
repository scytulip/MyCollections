class Solution {
public:
    int divide(int dividend, int divisor) {
        
        int rt_val;
        int shift;
        int tmp,k;
        
        if (dividend==0) return 0;
        if (divisor==1) return dividend;
        if (divisor==-1) return -dividend;
        if (divisor==-2147483648)
        {
            if (dividend==-2147483648)
                return 1;
            else
                return 0;
        }
        
        bool max_div = false;
        bool neg = false;
        if ((dividend>0 && divisor<0) || (dividend<0 && divisor>0)) neg = true;
        if (dividend==-2147483648) max_div=true;
        dividend = (dividend==-2147483648) ? 2147483647 : abs(dividend);
        divisor = abs(divisor);
        
        tmp = dividend;
        shift = 0;
        while (tmp>divisor) {tmp = tmp>>1; shift++;}
        
        rt_val = 0;
        tmp = dividend;
        while (shift>=0)
        {
            if ((tmp>>shift)>=divisor) // Avoid overflow
            {
                tmp -= (divisor<<shift);
                rt_val += (1<<shift);
            }
            shift --;
        }
        
        if (tmp==divisor-1 && max_div==true) rt_val ++;
        
        return neg ? -rt_val : rt_val;
    }
};