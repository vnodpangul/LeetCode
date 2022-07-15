class Solution {
    map<char, string> mp;
    set<string> keys;
public:
    bool wordPattern(string pattern, string s) {
        vector<string> strs;
        stringstream iss(s);
        while(iss) {
            string str="";
            iss >> str;
            // cout<<str<<endl;
            if(str != "") strs.push_back(str);
        }
        // cout<<strs.size()<<endl;
        
        if(pattern.size() != strs.size()) return false;
        for(int i=0; i<pattern.size(); i++)
        {
            if(mp.count(pattern[i])>0)
            {
                if(strs[i]!=mp[pattern[i]]) return false;
            }else
            {
                if(keys.count(strs[i])>0) return 0; 
                mp[pattern[i]] = strs[i];
                keys.insert(strs[i]);
            }
        }
        
        return true;
    }
};
