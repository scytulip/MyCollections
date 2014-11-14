class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> rt_val;
        int i,x,y;
        int bu, bd, bl, br;
        
        if (matrix.size()==0) return rt_val;
        
        bu = 0;
        bd = matrix.size()-1;
        bl = 0;
        br = matrix[0].size()-1;
        
        while (bu<=bd && bl<=br)
        {
            if (bu<=bd) for(i=bl; i<=br; i++) rt_val.push_back(matrix[bu][i]);
            bu ++;
            
            if (bl<=br) for(i=bu; i<=bd; i++) rt_val.push_back(matrix[i][br]);
            br --;
            
            if (bu<=bd) for(i=br; i>=bl; i--) rt_val.push_back(matrix[bd][i]);
            bd --;
            
            if (bl<=br) for(i=bd; i>=bu; i--) rt_val.push_back(matrix[i][bl]);
            bl ++;
        }
    }
};