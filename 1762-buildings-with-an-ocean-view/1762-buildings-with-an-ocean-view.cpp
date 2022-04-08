class Solution {
public:
    vector<int> findBuildings(vector<int>& h) {
        stack<int> st;
        vector<int> rc;
        if(h.size()==0) return rc;
        
        st.push(h[h.size()-1]);
        rc.push_back(h.size()-1);
        
        for(int i=h.size()-2; i>=0; i--) {
            if(h[i]>st.top()) {
                st.push(h[i]);
                rc.push_back(i);
            }
        }
        
        reverse(rc.begin(), rc.end());
        return rc;
    }
};




// 7,4,2,6,1,5,3

// 7
// 6
// 5
// 3