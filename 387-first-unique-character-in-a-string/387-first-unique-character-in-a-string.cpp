class Solution {
public:
    int firstUniqChar(string s) {
        map<char, pair<int, int>> mp;
        for(int i=0; i<s.size(); i++) {
            if(mp.find(s[i]) == mp.end()) {
                mp[s[i]] = make_pair(1, i);
            }else {
                mp[s[i]].first++;
            }
        }
        
        for(int i=0; i<s.size(); i++) {
            if(mp[s[i]].first == 1) return i;
        }
        return -1;
    }
};