class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i;
        int len = n;
        
        for (i=0; i<len; i++)
            if (A[i]==elem)
            {
                A[i] = A[len-1];
                i --;
                len --;
            }
        
        return len;
    }
};