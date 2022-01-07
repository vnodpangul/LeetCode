class Solution {
public:
    
    void helper(string s, int start, string str)
    {
        if(start == s.size()) {
            rc.insert(str);
            return;
        }
        
        for(int end=start+1; end<=s.size(); end++) {
            string tmp = s.substr(start, end-start);
            if(wordDictSet.count(tmp)>0) {
                helper(s, end, str==""?str+tmp:str+" "+tmp);
            } 
        }
            
        
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        for(auto w: wordDict)
            wordDictSet.insert(w);
        
        vector<string> rc_vec;
        string tmp="";
        helper(s, 0, tmp);
        for(auto s: rc)
            rc_vec.push_back(s);

        return rc_vec;
    }
    private:
        set<string> wordDictSet;
    set<string> rc; 
};