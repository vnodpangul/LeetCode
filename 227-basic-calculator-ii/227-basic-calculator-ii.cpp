class Solution {
public:
    int calculate(string s) {
        int res = 0;
        stack<int> st;
        
        char sign = '+', nextSign = '+';
        int i=0; int num = 0;
        while(i<s.size()) {
            while(isspace(s[i])) i++;
            while(isdigit(s[i]) && i<s.size()) {
                num = num*10 + (s[i]-'0');
                i++;
            }
            if(i<s.size() && isspace(s[i])) i++;
            nextSign = s[i];
            
            int tmp = 0;
            switch(sign) {
                    case '+':
                        st.push(num);
                        sign = nextSign;
                        num = 0;
                        break;
                    case '-':
                        st.push(-1* num);
                        sign = nextSign;
                        num = 0;
                        break;
                    case '*':
                        tmp = st.top(); st.pop();
                        st.push(tmp*num);
                        sign = nextSign;
                        num = 0;
                        break;
                    case '/':
                        tmp = st.top(); st.pop();
                        tmp = tmp/num;
                        st.push(tmp);
                        sign = nextSign;
                        num = 0;
                        break;
            }
            i++;
        }
        
        if(num>0) {
            if (sign == '-') num = -1*num;
            st.push(num);
        }
        
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        
        return res;
    }
};
