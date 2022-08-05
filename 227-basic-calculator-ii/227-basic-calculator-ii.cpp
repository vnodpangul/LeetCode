class Solution {
    stack<int> st;
    long num=0;
    char sign = '+';
public:
    int calculate(string s) {
        
        int i=0; 
        while(i<s.size())
        {
            while(i<s.size() && s[i]==' ') i++;
            while(isdigit(s[i]))
            {
                num = num*10 + s[i]-'0';
                i++;
            }
            while(i<s.size() && s[i]==' ') i++;
            char ch = s[i]; i++;

            
            switch(sign)
            {
                case '+':
                    st.push(num);
                    break;
                 case '-':
                    st.push(-1*num);
                    break;
                 case '*': {
                    int n = st.top(); st.pop();
                    st.push(n*num);
                    break;
                 }
                 case '/': {
                    int n = st.top(); st.pop();
                    st.push(n/num);
                    break;
                 }
                default:
                    cout<<"unknown op\n";
                    // return -1;
                    break;
            }
            num=0;
            sign = ch;
        }
        
        if(num>0) {
            st.push(num);
        }
        long res = 0;
        while(!st.empty())
        {
            res += st.top(); st.pop();
        }
        return (int)res;
        
    }
};

// sign = '+'
// num 
// stack<int> st