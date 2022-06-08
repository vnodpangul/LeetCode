class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        unordered_set<string> st;
        for(auto w: wordDict)
            st.insert(w);
        
        vector<bool> dp(n+1, false);
        dp[0] = true;
        
        for(int i=1; i<=n; i++) {
            for(int j=0; j<i; j++) {
                // cout<<i<<":"<<j<<s.substr(j, i)<<endl;
                if(dp[j] && st.count(s.substr(j, i-j))>0) {
                    dp[i] = true;
                    break;
                }
                
            }
        }
        
        return dp[n];
    }
};