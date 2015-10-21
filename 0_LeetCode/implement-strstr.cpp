/*
Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
*/

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        
        int i,j;
        
        int len_hay = strlen(haystack); // Length of each string
        int len_nee = strlen(needle);
        
        if (len_nee>len_hay) return NULL;
        
        for (i=0; i<len_hay-len_nee+1; i++)
        {
            for (j=0; j<len_nee; j++)
            {
                if (haystack[i+j] != needle[j]) break;
            }
            if (j==len_nee) return &haystack[i]; // Matched
        }
        
        return NULL;
    }
};