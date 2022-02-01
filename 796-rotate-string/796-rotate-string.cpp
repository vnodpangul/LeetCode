class Solution {
public:
    bool rotateString(string s, string goal) {
        
        bool rc = false;
        if(s.size() != goal.size()) return rc;
        if(s.size()==1 & s!=goal) return rc;
        
        for(int i=0; i<=s.size(); i++) {
            if(s == goal) return true;
            char start = s[0];
            s = s.substr(1); s.push_back(start);
        }
        
        return rc;
        
        
    }
};