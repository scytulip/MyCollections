class Solution {
public:
    int maxArea(vector<int>& height) {
        int largest = 0;
        int n = height.size();
        int a,b,v,h;
    
        a = 0;
        b = n-1;
        while (a<=b)
        {
            h = (height[a]<height[b])?height[a]:height[b];
            v = h*(b-a);
            if (v>largest) largest=v;
    
            while(a<=b && height[b]<=h) b --;
            while(a<=b && height[a]<=h) a ++;
        }
    
        return largest;
    }
};