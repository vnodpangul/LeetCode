class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> lessLeft(n), lessRight(n);
        stack<int> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && heights[st.top()]>= heights[i]) st.pop();
            lessLeft[i] = (st.empty()) ? 0 : st.top()+1;
            st.push(i);
        }
        
        // Clear the stack
        while(!st.empty()) st.pop();
        
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            lessRight[i] =  (st.empty()) ? n-1 : st.top()-1;
            st.push(i);
        }
        
        int areaMax = 0;
        for(int i=0; i<n; i++) {
            areaMax = max(areaMax, abs((lessRight[i]- lessLeft[i] +1 )*heights[i]) );
        }
        
        return areaMax;
    }
};


