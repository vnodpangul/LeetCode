class Solution {
private:
    map<char, int> mp;
    vector<string> res;

public:
    
    void helper(string tmp, int n)
    {
        if(tmp.size()==n)
        {
            res.push_back(tmp);
            return;
        }
        
        for(auto it=mp.begin(); it!=mp.end(); it++)
        {
            if(it->second>0) {
                it->second -= 2;
                string new_tmp = it->first + tmp + it->first;
                helper(new_tmp, n);
                it->second += 2;
            }   
            
        }
    }
    
    vector<string> generatePalindromes(string s) {
        for(auto ch : s)
            mp[ch]++;
        
        int count = 0;
        for(auto &elm : mp)
        {
            if(elm.second%2!=0) count++;
        }
        if(count>1) return res;
        
        
        string tmp = "";
        for(auto &elm: mp)
        {
            if(elm.second%2 != 0)
            {
                tmp += elm.first;
                mp[elm.first]--;
                break;
            }
        }
        if(tmp.size()==s.size()) {
            res.push_back(tmp);
            return res;
        }
        
        helper(tmp, s.size());
        return res;
    }
};