class Solution {
    stack<int> st;
    char sign = '+', ch='+';
    long res=0, prev=0, num=0;
public:
    int calculate(string s) {
        
        int i=0; 
        while(i<s.size())
        {
            while(i<s.size() && s[i]==' ') i++;
            while(isdigit(s[i]))
            {
                num = num*10 + (s[i]-'0');
                i++;
            }
            while(i<s.size() && s[i]==' ') i++;
            ch = s[i]; i++;

            switch(sign)
            {
                case '+':
                case '-':
                    res += prev;
                    prev = (sign == '+') ? num : -1*num;
                    break;
                 case '*': {
                    prev *= num;
                    break;
                 }
                 case '/': {
                    prev /= num;
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
        
        res += prev;
        return (int)res;
        
    }
};

// sign = '+'
// num 
// stack<int> st