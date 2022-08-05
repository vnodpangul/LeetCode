class Solution {
    

public:
    int calculate(string s) {
        int idx=0;
        return parseExp(s, idx);
    }
    
    int parseExp(string &s, int &i)
    {
        vector<int> nums;
        char op = '+';
        for( ; i<s.size() && op !=')'; i++)
        {
            if(s[i]==' ') continue;
            int num = (s[i]=='(') ? parseExp(s, ++i) : parseNum(s, i);
            switch(op)
            {
                case '+':
                    nums.push_back(num); break;
                case '-':
                    nums.push_back(-1*num); break;   
                case '*':
                    nums.back() *= num; break;
                case '/':
                    nums.back() /= num; break;
            }
            if(i<s.size()) op = s[i];
        }
        int res = 0;
        for(auto n : nums) res += n;
        return res;
        
    }
    
    int parseNum(string &str, int &i)
    {
        int n=0;
        while(i<str.size() && isdigit(str[i]))
        {
            n = (n*10) + (str[i]-'0');
            i++;
        }
        return n;
    }
    

};