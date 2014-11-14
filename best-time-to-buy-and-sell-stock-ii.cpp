class Solution {
public:
    int maxProfit(vector<int> &prices) {
        
        vector<int> valley;
        vector<int> peak;
        int lv = 0;
        int lp = 0;        
        
        int i,j;
        int len = prices.size();
        bool down = true;
        
        int maxp = 0;
        
        if (len<=1) return 0;
        
        /* Find valleys and peaks */
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
        
        /* Sell and buy */
        // # of peaks == # of valleys
        // Always buy at valleys and sell at peaks
        for (i=0; i<lv; i++)
        {
            maxp += prices[peak[i]]-prices[valley[i]];
        }
        
        
        return maxp;
        
    }
};