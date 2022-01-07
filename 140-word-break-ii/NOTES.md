```
class Solution {
public:
void helper(set<string> &st, string s, int start, string res, set<string> &rc) {
if(start == s.size()) {
rc.insert(res);
return;
}
for(int end=start+1; end<=s.size(); end++) {
string tmp = s.substr(start, end-start);
if ((st.count(tmp) != 0))
// res = (res !="") ? res+" "+tmp : res+tmp;
helper(st, s, end, (res !="") ? res+" "+tmp:res+tmp, rc);
}
}
vector<string> wordBreak(string s, vector<string>& wordDict) {
set<string> rc;
set<string> st(wordDict.begin(), wordDict.end());
string res="";
helper(st, s, 0, res, rc);
vector<string> rc_vec(rc.begin(), rc.end());
return rc_vec;
}
};
```