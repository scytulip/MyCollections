class Solution {
public:
    int maxProfit(vector<int> &prices) {
        
        vector<int> valley;
        vector<int> peak;
        int i,j;
        int maxp = 0, lv = 0, lp = 0;
        int len = prices.size();
        bool down = true;
        
        if (len<=1) return 0;
        if (prices[1]>prices[0]) 
        {
            valley.push_back(0);
            down = false;
            lv ++;
        }
        
        for (i=0; i<len-1; i++)
        {
            if (down==true && prices[i+1]>prices[i])
            {
                down=false;
                valley.push_back(i);
                lv ++;
            }
            if (down==false && prices[i+1]<prices[i])
            {
                down=true;
                peak.push_back(i);
                lp ++;
            }
        }
        
        if (down==false)
        {
            peak.push_back(len-1);
            lp ++;
        }
        
        for (i=0; i<lv; i++)
        {
            for (j=0; j<lp; j++)
            {
                if (peak[j]>valley[i] && prices[peak[j]]-prices[valley[i]]>maxp)
                    maxp = prices[peak[j]]-prices[valley[i]];
            }
        }
        
        return maxp;
        
    }
};