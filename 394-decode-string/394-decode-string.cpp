class Solution {
    
public:
    string decodeString(string s) {  
        string res="";
        int i=0;
        while(i<s.size()) {
            char ch = s[i];
            switch(ch) {
                case ']': {
                    i++;
                    string str = "";
                    while(st.top()!='[') {
                        str += st.top(); st.pop();
                    }
                    st.pop();
                    int n = 1; // 0 0 1
                    int k = 0;
                    while(!st.empty() && isdigit(st.top())) {
                        k = n * (st.top() - '0') + k; // k = 0, n = 10 x0 + 0 = 10, n=100 
                        n = n * 10;
                        st.pop();
                    }
                    string dstr = "";
                    for(int j=0; j<k; j++)
                        dstr += str;
                    for(int j=dstr.size()-1; j>=0; j--)
                        st.push(dstr[j]);
                    
                    break;
                }
                default: {
                    st.push(ch);
                    i++;
                    break;
                }
            }
        }
        
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    
    }
private:
    stack<char> st;
};
