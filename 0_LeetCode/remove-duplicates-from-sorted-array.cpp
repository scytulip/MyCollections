class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i,j;
        
        if (n==0 || n==1) return n;
        
        i=0; j=1; // Two pointers
        
        while(j<n)
        {
            if (A[i]==A[j] && j<n)
                j++;
            else
            {
               i++;
               A[i]=A[j];
               j++;
            }
        }
        
        return i+1;
    }
};