class Solution {
    map<char, int> lastSeenAt;
public:
    long long appealSum(string s) {
        if(s.empty()) return 0;
        
        long res = 1, prev =1, tmp = 0;
        lastSeenAt[s[0]] = 0;
        
        for(int i=1; i<s.size(); i++)
        {
            
            if(lastSeenAt.count(s[i]))
            {
                tmp = prev + (i-lastSeenAt[s[i]]);
            }
            else
            {
                tmp = prev + (i+1);
            }
            
            res += tmp;
            prev = tmp;
            lastSeenAt[s[i]] = i;
            
        }
        
        return res;
    }
};