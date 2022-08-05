class Solution {
    stack<int> st;
    int res = 0, num = 0;
    int sign = 1;
public:

    int calculate(string s) {
        
        for(int i=0; i<s.size(); i++)
        {
            if(isdigit(s[i]))
            {
                num = (num *10) + (s[i]-'0'); 
            }
            else if(s[i]=='+')
            {
                res += num*sign;
                sign = 1;
                num = 0;
            }
            else if(s[i]=='-')
            {
                res += num*sign;
                sign = -1;
                num = 0;
            }
            else if(s[i]=='(')
            {
                st.push(res);
                st.push(sign);
                
                num=0; res=0; sign = 1;
            }
            else if(s[i]==')')
            {
                res += (num*sign);
                
                res *= st.top(); st.pop(); //sign
                res += st.top(); st.pop(); // prev res
                
                num=0; sign = 1;
                // cout<<"res : "<<res<<endl;
            }
        }
        
        if(num>0)
            res += (num*sign);
        
        return res;
    }
};