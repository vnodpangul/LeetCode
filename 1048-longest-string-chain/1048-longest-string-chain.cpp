class Solution {
public:
    
    int helper(set<string> &st, map<string, int> &mp, string word) {
        
        if(mp.find(word) != mp.end()) {
            return mp[word];
        }
        
        int count = 1;
        for(int i=0; i<word.size(); i++) {
            string tmp = word.substr(0, i) + word.substr(i+1);
            if(st.count(tmp)>0){
                int currLen = 1 + helper(st, mp, tmp);
                count = max(count, currLen);
            } 
        }
        mp[word] = count;
        return mp[word];
    }
    
    
    int longestStrChain(vector<string>& words) {
        set<string> st;
        for(auto &w: words) {
            st.insert(w);
        }
        
        map<string, int> mp;
        int maxRc = 0;
        for(auto &word: words) {
            maxRc = max(maxRc, helper(st, mp, word));
        }
        return maxRc;
    }
};