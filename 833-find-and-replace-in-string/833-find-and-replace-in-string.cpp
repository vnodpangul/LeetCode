class Solution {
public:
    bool isStartsWith(const string &s, const string &sub, int idx)
    {
        int len = sub.size();
        string str = s.substr(idx, len);
        if(str == sub) return true;
        else return false;
        
    }
    
    /*
    0--a
    2--cd
    
    0--eee
    2--ffff
    
    */
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string res;
        map<int, string> sourceMp, targetMp;
        for(int i=0; i<indices.size(); i++)
        {
            int idx = indices[i];
            sourceMp[idx] = sources[i];
            targetMp[idx] = targets[i];
        }
        
        int i=0;
        while(i<s.size())
        {
            if(sourceMp.count(i)>0 && isStartsWith(s, sourceMp[i], i))
            {
                res += targetMp[i];
                i += sourceMp[i].size();
            }else {
                res += s[i];
                i++;
            }
        }
        
        return res;
    }
};

/*
0--a
1--bc

0--eee
1--ffff

str=""
str +=eee
i += .size();
*/
