class Solution {
public:
    void helper(string &s, int start, string str)
    {
        if(start == s.size()) {
            res.push_back(str);
            return;
        }
        for(int end=start+1; end<=s.size(); end++) {
            string tmp = s.substr(start, end-start);
            if(dict.count(tmp)>0) {
                helper(s, end, str==""? str+tmp: str+" "+tmp);
            }
            
        }
        
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        for(auto w: wordDict)
            dict.insert(w);
        
        string tmp = "";
        helper(s, 0, tmp);
        return res;
    }
    private:
        set<string> dict;
        vector<string> res;
};