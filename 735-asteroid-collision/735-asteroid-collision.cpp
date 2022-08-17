class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for(int i=0; i<n ; i++)
        {
            // Add all +ve or first -ve stones
            if(st.empty() || asteroids[i]>0)
            {
                st.push(asteroids[i]);
            }else {
                
                // -ve stones destroys +ve stones
                while(!st.empty() && st.top()>0 && st.top()<abs(asteroids[i])) {
                    st.pop();
                } 
                
                // equal collision
                if(!st.empty() && st.top()==abs(asteroids[i])) {
                    st.pop();
                }else {
                    // adds -ve stone
                    if(st.empty() || st.top()<0)
                        st.push(asteroids[i]);
                }   
            }
        }
        n = st.size();
        vector<int> res(n);
        for(int i=n-1; i>=0; i--)
        {
            res[i]=st.top();
            st.pop();
        }
        return res;
    }
};