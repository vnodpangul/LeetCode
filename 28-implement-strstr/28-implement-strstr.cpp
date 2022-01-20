#if 0
// TLE Error 
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0) return 0;
        if(needle.size()>haystack.size()) return -1;
        int r=0, i=0, idx=0;
        
        while(i<haystack.size() && r<needle.size()) 
        // while(i<=haystack.size()-needle.size()) 
        {
            if(haystack[i] == needle[r]) {
                r++;
                i++;
            }else {
                idx++;
                i = idx;
                r=0;
            }
            
            if(r==needle.size()) return idx;
        }
        
        return -1;
    }
};
#endif

#if 1
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n= needle.size();
        for(int i=0; i<=m-n; i++) {
            int j=0;
            for(; j<n; j++) {
                if(haystack[i+j] != needle[j]) break;
            }
            if(j==n) return i;
        }
        return -1;
    }
};
#endif



    
