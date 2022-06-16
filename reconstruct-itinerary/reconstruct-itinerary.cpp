class Solution {
    
    unordered_map<string, priority_queue<string, vector<string>, greater<string>> > adjList;
    vector<string> res;
    
    stack<string> st;
public:
    
    void DFS(string src) {
        
        st.push(src);
        // cout<<src<<endl;
        while(adjList[src].size()>0) {
            auto dest = adjList[src].top(); adjList[src].pop();
            DFS(dest);
        }
        
        res.push_back(st.top()); st.pop();
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        for(auto &t : tickets) {
            adjList[t[0]].push(t[1]);
        }
        
        DFS("JFK");        
        
        reverse(res.begin(), res.end());
        return res;
    }
};


/*
[["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
JFK-->
SFO-->
ATL-->SFO


<JFK, ATL, SFO, 
<JFK --> ATL-->JFK-->SFO-->ATL-->SFO>

[["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]
JFK--> KUL, NRT
NRT--> JFK

JFK-->KUL
*/