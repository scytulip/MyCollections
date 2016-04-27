class Solution {
public:
    string numberToWords(int num) {
        if (0==num) {
            return "Zero";
        } else {
            string val;
            
            for (int i=0; i<4; ++i) {
                val = ((num/1000>0 && num%1000>0)?" ":"") + numToWords1K(num%1000) + ((num%1000>0)?sep[i]:"") + val; 
                num /= 1000;
            }
            
            return val;
        }
    }
private:
    const string sep[4] = {
        "", " Thousand", " Million", " Billion"
    };
    const string numstr[20] = {
        "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
        "Seventeen", "Eighteen", "Nineteen"
    };
    const string prefix[8] = {
        "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };
        
    string numToWords1K(int num) {
        if (num==0) return "";
        
        string val;
        if (num%100 < 20)
            val = numstr[num % 100];
        else
            val = prefix[num%100/10-2] + ((num%10>0)?" ":"") + numstr[num%10];
            
        if (num/100 > 0)
            val = numstr[num/100] + " Hundred" + ((num%100>0)?" ":"") + val;
            
        return val;
    }
};