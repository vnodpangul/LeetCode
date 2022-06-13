// https://www.youtube.com/watch?v=O3jr8HOpkUU&ab_channel=CodingDecoded
class Solution {
private:
    vector<int> parents;
    int count = 0;
    
    unordered_map<int, priority_queue<char, vector<char>, greater<char>> > keys;
public:
    int find(int x) {
        if(parents[x]!=x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }
    
    void makeUnion(int a, int b)
    {
        int x = find(a);
        int y = find(b);
        if(x!=y) {
            parents[y] = x;
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        parents.resize(n, -1);
        for(int i=0; i<n; i++)
            parents[i] = i;
        count = n;
        
        for(auto &p : pairs) {
            makeUnion(p[0], p[1]);
        }
        
        for(int i=0; i<n; i++) {
            int key = find(i);
            keys[key].push(s[i]);
        }
        
        string res = "";
        for(int i=0; i<n; i++) {
            int key = find(i);
            res += keys[key].top();
            keys[key].pop();
            
        }
        
        return res;
        
    }
};
