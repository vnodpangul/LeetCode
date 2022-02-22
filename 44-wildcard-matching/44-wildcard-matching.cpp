/*
s  p
// a****bc**cc
-- Cleanp to a*bc*cc

- s == p return T
- p == '*' return T
- p == ' ' || s == ' ' return F

-- p[0] != s[0] return F
-- p[0] == s[0] ||  p[0] == '?'
    return isMatch(p[1:], s[1:])
-- p[0] == '*'
    isMatch(s, p[1:]) ||
    isMatch(s[1:], p)
*/

/* 
    Approach 1 : Recursion w/o Memomisation
    TLE Error
*/

#if 0
class Solution {
public:
    void sanitizeP(string &p) {
        
        int idx = 0;
        for(int i=1; i<p.size(); i++) {
            if(p[i] == '*' && p[i] == p[i-1]) {
                continue;
            }else {
                idx++;
                p[idx] = p[i];
            }
        }
        p = p.substr(0, idx+1);
        // cout<<" Pattern :"<<p<<endl;
    }
    
    bool helper(string &s, string& p)
    {
        if(s==p) return true;
        if(p == "*") return true;
        if(s=="" || p=="") return false;
        
       
        if(s[0] == p[0] || p[0] == '?')
            return helper(s.substr(1), p.substr(1));
        if(p[0] == '*')
            return helper(s, p.substr(1)) || helper(s.substr(1), p);
        
        if(s[0] != p[0]) return false; // This strong check needs to be in the end
        return false; 
        
    }
    
    bool isMatch(string s, string p) {
        
        sanitizeP(p);
        return helper(s, p);
        // return true;
        
    }
    
};
#endif

#if 0
/* 
    Approach 2 : Recursion with Memomisation
*/

class Solution {
public:
    void sanitizeP(string &p) {
        
        int idx = 0;
        for(int i=1; i<p.size(); i++) {
            if(p[i] == '*' && p[i] == p[i-1]) {
                continue;
            }else {
                idx++;
                p[idx] = p[i];
            }
        }
        p = p.substr(0, idx+1);
        // cout<<" Pattern :"<<p<<endl;
    }
    
    bool helper(string s, string p)
    {
        string key = s+"_"+p;
        if(dp.find(key) != dp.end())
            return dp[key];
        if(s==p || p=="*") 
            dp[key] = true;
        else if(s=="" || p=="") 
            dp[key] = false;

        else if(s[0] == p[0] || p[0] == '?')
            dp[key] = helper(s.substr(1), p.substr(1));
        else if(p[0] == '*')
           dp[key] = helper(s, p.substr(1)) || helper(s.substr(1), p);
        
        // else if(s[0] != p[0]) 
        else
            dp[key] = false; // This strong check needs to be in the end
        
        
        return dp[key];
        
    }
    
    bool isMatch(string s, string p) {
        
        sanitizeP(p);
        return helper(s, p);
    }
private:
    unordered_map<string, bool> dp;
    
};
#endif



#if 0
/* 
    Approach 3 : Linear Time & constant space solution
    
    Worst case definitely not linear. Should be O(NM)
    think that s ="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" to match p ="*aaaaaab"( '*' in the beginning)
    It's easy to see 'match' is moving step by step to almost the end, each time we move 'match', we will go through the whole tail of p (after '*') until we found out 'b' is not a match. Thus it's O(NM)

*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int i=0, j=0;
        int sIdx = 0, starIdx = -1;
        while(i<s.size()) {
            if(j<p.size() && (s[i]==p[j] || p[j]=='?')) {
                i++;
                j++;
            }else if(p[j]=='*') {
                starIdx = j;
                sIdx = i;
                j++;
            }else if(starIdx != -1) {
                j = starIdx+1;
                sIdx++;
                i= sIdx;
            }else {
                return false;
            }
        }
        
        while(j<p.size() && p[j]=='*') j++;
        return j==p.size();
    }
private:
    
};
#endif

#if 1
/* 
    Approach 4 : Dynamic Programming
    Complexity : O(NM)
*/

class Solution {
public:
    
    void sanitizeP(string &p) {
        int idx = 0;
        for(int i=1; i<p.size(); i++) {
            if(p[i] == '*' && p[i]==p[i-1]) 
                continue;
            else {
                idx++;
                p[idx] = p[i];
            }
        }
        p = p.substr(0, idx+1);
    }
    
    bool isMatch(string s, string p) {
        sanitizeP(p);
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        
        dp[0][0] = true;
        if(p.size()>0 && p[0]=='*') {
            dp[0][1] = true;
        }
        
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(s[i-1]==p[j-1] || p[j-1]=='?') {
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }else {
                    dp[i][j] = false;
                }
            }
        }
        
//         for(int i=0; i<=m; i++) {
//             for(int j=0; j<=n; j++) {
//                 cout<<dp[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        return dp[m][n];
        
    }
private:
    
};
#endif


