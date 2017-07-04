/*
157. Read N Characters Given Read4  QuestionEditorial Solution  My Submissions
Total Accepted: 13952
Total Submissions: 47427
Difficulty: Easy
The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Note:
The read function will only be called once for each test case.
*/

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int actual = 0;
        char tmp[4];
        
        int nch = 4;
        while (nch==4 && n>actual) {
            nch = read4(tmp);
            memcpy(buf+actual, tmp, min(nch, n-actual));
            actual = min(actual+nch, n);
        }
        
        return actual;
    }
};