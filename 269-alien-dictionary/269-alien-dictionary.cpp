class Solution {
public:
    bool buildGraph(const vector<string> &words) {
        
        for(auto word: words) {
            for(auto ch: word) {
                inDegree[ch] = 0;
            }
        }
        
        for(int i=1; i<words.size(); i++) {
            int prevSz = words[i-1].size(), currSz = words[i].size(), j=0;
            string prev = words[i-1], curr = words[i];
            
            while (j<prevSz && j<currSz && prev[j]==curr[j]) j++;
            
            if(j<prevSz && j==currSz) return false;
            if(j<prevSz && j<currSz) {
                adjList[prev[j]].push_back(curr[j]);
                inDegree[curr[j]]++;
            }
        }
        return true;
    }
    
    string alienOrder(vector<string>& words) {
        if(words.size()==0) return ""; 
        if(!buildGraph(words)) return "";
                
        // Perform topological Sort
        queue<char> _q;
        for(auto &elem : inDegree) {
            if(elem.second == 0) {
                // cout<<"\n "<<elem.first<<": "<<elem.second;
                _q.push(elem.first);
            }       
        }
        
        string rc = "";
        while(!_q.empty()) {
            char node = _q.front(); _q.pop();
            // cout<<"\n NodePopped: "<<node;
            rc += node;
            // cout<<"\n Rc :" <<rc.size()<<" & adjList.size(): "<<inDegree.size();
            
            for(auto v : adjList[node]) {
                inDegree[v]--;
                if(inDegree[v] == 0) {
                    _q.push(v);
                }   
            }
            
        }
        for(auto &elem : inDegree) {
            if(elem.second>0) return "";
        }
        
        return rc;
    }
private:
    map<char, vector<char>> adjList;
    map<char, int> inDegree;
};


