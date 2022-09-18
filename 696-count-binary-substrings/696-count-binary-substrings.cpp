class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int i=1, curr = 1, prev=0;
        int count = 0;
        
        while(i < s.size())
        {
            if(s[i] != s[i-1]) {
                
                count += min(prev, curr);
                prev = curr;
                curr = 1;
            }else {
                curr++;
            }
            i++;
        }
        
        return count += min(prev, curr);
        
        
    }
};