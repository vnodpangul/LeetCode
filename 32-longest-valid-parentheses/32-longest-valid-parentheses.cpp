#if 0
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        stack<int> st;
        st.push(-1);
        
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') {
                st.push(i);
            }else if(s[i] == ')') {
                st.pop();
                if(st.empty()) {
                    st.push(i);
                }else {
                    int len = i- st.top(); 
                    maxLen = max(maxLen, len);
                }
            }    
        }
        
        return maxLen;
    }
};
#endif 

#if 1
class Solution {
public:
    int longestValidParentheses(string s) {
        int open=0, close=0;
        int maxLen = 0;
        
          for(int i=0; i<s.size(); i++) { // open=2  close=1
            if(s[i] == '(') {
                open++;
            }else {
                close++;
            }
            
            if(close>open) {
                open=0;
                close=0;
            }else if(open==close) {
                maxLen = max(maxLen, open+close);
            }
          }
        
         open=0, close=0;
         for(int i=s.size()-1; i>=0; i--) {
            if(s[i] == '(') {
                open++;
            }else {
                close++;
            }
            if(open>close) {
                open=0;
                close=0;
            }else if(open==close){
                maxLen = max(maxLen, open+close);
            }
         }
        
        return maxLen;
        
    }
};
#endif

