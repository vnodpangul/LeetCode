class Solution {
    map<char, string> mp;
    set<string> st;
public:
    bool helper(string &p, int i, string &str, int j)
    {
        if(i==p.size() && j==str.size()) return true;
        if(i==p.size() || j==str.size()) return false;
        
        char ch = p[i];
        if(mp.count(ch))
        {
            string s = mp[ch];
            if(s != str.substr(j, s.size())) return false;
            
            return helper(p, i+1, str, j+s.size());
        }
        
        for(int k=j; k<str.size(); k++)
        {
            string s2 = str.substr(j, (k-j)+1);
            if(st.count(s2)) continue;
            
            mp[ch] = s2;
            st.insert(s2);
            
            if(helper(p, i+1, str, k+1)) {
                return true;
            }
            mp.erase(ch);
            st.erase(s2);
            
        }
        return false;
        
    }
    
    
    bool wordPatternMatch(string pattern, string s) {
        
        
        return helper(pattern, 0, s, 0);
        
        
        
    }
};