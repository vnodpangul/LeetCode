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


// "((**(*" --> n = 6
    

