#if 1
class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if(k>=num.size())
            return "0";
        
        string st;
        for(int i=0; i<num.size(); i++) {
            while(st.size()>0 && st.back()>num[i] && k>0) {
                // cout<<"\n Size: "<<st.size();
                st.pop_back();
                k--;
            }
            st +=num[i];
        }
        
        while(!st.empty() && k>0) {
            st.pop_back(); k--;
        }
        
        int i=0;
        while(i<st.size() && st[i]=='0')
            i++;
            
        return i==st.size() ? "0" : st.substr(i);
        
    }
};
#endif