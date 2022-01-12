/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        if(buf == nullptr)
            return 0;
        
        int totalCharsRead = 0;
        char *buf4 = new char[4];
        int totalCalls = n%4 == 0 ? n/4 : n/4 + 1;
        
        for(int i=0; i<totalCalls; i++) {
            int readCount = read4(buf4);
            if(readCount<n){
                totalCharsRead += readCount;
                n = n-readCount;
                strncpy(buf+4*i, buf4, readCount);
            }else {
                totalCharsRead += n;
                strncpy(buf+4*i, buf4, n);
                n = n-n;
            }
            buf4[0]='\0';
        }
        
        return totalCharsRead;
        
    }
};