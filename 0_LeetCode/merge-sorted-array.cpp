class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i,j,k,alen;
        
        if (n==0) return;
        
        alen = m;
        j = 0;
        
        for (i=0; i<n; i++) // pick a # in B
        {
            while(A[j]<=B[i] && j<alen) j++;
            
            if (j<alen)
            {
                for (k=alen; k>j; k--) A[k]=A[k-1];
            }
            
            A[j] = B[i];
            alen ++;
        }
    }
};