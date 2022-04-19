class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        int maxElem = INT_MIN;
        for(auto ch: s) {
            mp[ch]++;
            maxElem = max(maxElem, mp[ch]);
        }
        
       unordered_map<int, vector<char>> list_mp;
       set<int> idx;
        for(auto &elem : mp) {
            list_mp[elem.second].push_back(elem.first);
            idx.insert(elem.second);
        }
        
        string res = "";
        for(int i=maxElem; i>=1; i--) {
            if(list_mp.find(i) != list_mp.end() && idx.count(i)>0) {
                auto vec = list_mp[i];
                for(auto ch : vec)
                    for(int j=0; j<i; j++) 
                        res += ch;
            }
        }
        
        return res;
    }
};