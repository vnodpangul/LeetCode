class Solution {
    stack<int> st;
public:
    void performOp(string op)
    {
        const char *ch = op.c_str();
        switch(*ch) {
            case '+' : {
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();
                st.push(num1+num2);
                break;
            }
            case '-': {
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();
                st.push(num2-num1);
                break;
            }
            case '/': {
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();
                st.push(num2/num1);
                break;
            }
            case '*': {
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();
                st.push(num1*num2);
                break;
            }
            default:
                cout<<"\n Unknown Opearation";
                return;
        }
    }
    
    bool isOp(string op) {
        if(op=="+" || op=="-" || op=="/" || op=="*") return true;
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        
        
        for(auto t: tokens) {
            if(isOp(t)) {
               performOp(t); 
            }else {
                st.push(stoi(t));
            }
        }
        
        return st.top();
        
    }
};