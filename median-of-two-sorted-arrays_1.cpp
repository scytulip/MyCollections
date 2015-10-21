class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i,a,b;
        a = 0;
        b = 0;
        double val = 0;
        bool even = ((n1+n2)%2==0);
        
        if (n1==1 && n2==0)
            return nums1[0];
        else if (n1==0 && n2==1)
            return nums2[0];
        
        for (i=0; i<(n1+n2)/2+(even?0:1); i++)
        {
            
            if ((a<n1 && b<n2 && nums1[a]<=nums2[b]) || b==n2)
            {
                val = nums1[a];
                a++;
            } 
            else 
            {
                val = nums2[b];
                b++;
            }
        }
        
        if (even)
        {
            if ((a<n1 && b<n2 && nums1[a]<=nums2[b]) || b==n2)
                val += nums1[a];
            else
                val += nums2[b];
            
            val /= 2;
        }
        
        return val;
    
    }
};