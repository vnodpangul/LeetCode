#if 0
class Solution {
public:
    bool checkValidString(string s) {
        
        stack<int> st, op;
        int n = s.size();
        for(int i=0; i<n; i++) {
            switch(s[i]) {
                case '(':
                        st.push(i);
                        break;
                    
                case ')':
                        if(st.empty() && op.empty()) return false;
                        st.empty() ? op.pop() : st.pop();
                        break;
                
                case '*':
                    op.push(i);
                    break;
                
                default:
                    return false;
            }
        }
        
        if(!st.empty() && op.empty()) return false;
        while(!st.empty() && !op.empty()) {
            if(st.top()>op.top()) return false;
            else {
                st.pop();
                op.pop();
            }
        }
        
        return st.empty();
        return st.empty();
    }
};
#endif

#if 1
// Mathematical Approach
// https://leetcode.com/problems/valid-parenthesis-string/discuss/543521/Java-Count-Open-Parenthesis-O(n)-time-O(1)-space-Picture-Explain
class Solution {
public:
 bool checkValidString(string s) {
    int cmax=0, cmin=0;
    for(int i=0; i<s.size(); i++) {
        switch(s[i]) {
            case '(':
                cmax++; 
                cmin++;
                break;
            
            case ')':
                cmax--;
                cmin--;
                break;
            
            case '*':
                cmax++;
                cmin--;
                break;
            
            default:
                return false;
        }
        
        if(cmax<0) return false;
         cmin = max(cmin, 0);
    }
    
    return cmin==0;
 }
};
#endif

    

