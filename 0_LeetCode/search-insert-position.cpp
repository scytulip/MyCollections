class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int i,j;
        
        if (n==0) return 0;
        
        for (i=0; i<n; i++)
        {
            if (target==A[i]) return i;
        }
        
        for (i=0; i<n; i++)
        {
            if (A[i]>target) return i;
        }
        
        return n;
    }
};