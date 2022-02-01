class Solution {
public:
    
    void helper(int n, vector<string> &rc, string &str)
    {
        if(str.size() == 2*n && open==close) {
            rc.push_back(str);
            return;
        }
        if(open<=n) {
            str += "("; 
            open++;
            helper(n, rc, str);
            open--;
            str.pop_back();
        }
        if(close<=n && close<open) {
            str += ")";
            close++;
            helper(n, rc, str);
            close--;
            str.pop_back();
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> rc;
        string current = "";
        
        
        helper(n, rc, current);
        return rc;
        
        
    }
    private:
        int open=0, close=0;
};

// str = (())

// no_open = 3
// no_close = 0
// res = (()())