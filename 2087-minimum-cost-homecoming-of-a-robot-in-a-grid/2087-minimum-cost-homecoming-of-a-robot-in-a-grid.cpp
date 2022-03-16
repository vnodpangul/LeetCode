#if 0
// TLE - with BFS
class Solution {
private:

    vector<vector<int>> dirs = { {0,1}, {0,-1}, {1,0}, {-1,0}};
    
public:
    struct Node {
        int x, y, cost;
        Node(int _x, int _y, int _cost) : x(_x), y(_y), cost(_cost) {}
    };
    
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int m = rowCosts.size();
        int n = colCosts.size();
        
        int x = startPos[0], y=startPos[1];
        int end_x = homePos[0], end_y = homePos[1];
        
        int minCost = INT_MAX;
        queue<Node> q;
        Node elem = Node(x,y,0);
        q.push(elem);
        set<string> visited;
        
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                auto node = q.front(); q.pop();
                if(node.x == end_x && node.y == end_y) {
                    minCost = min(minCost, node.cost);
                }
                
                for(int i=0; i<dirs.size(); i++) {
                    int new_x = dirs[i][0] + node.x;
                    int new_y = dirs[i][1] + node.y;
                    if(new_x<0 || new_y<0 || new_x>=m || new_y>=n ||
                      visited.count(to_string(new_x)+"_"+to_string(new_y))>0) {
                        continue;
                    }
                    int cost = 0;
                    cost += (abs(dirs[i][0])==1) ? (node.cost + rowCosts[new_x]) :
                        (node.cost + colCosts[new_y]);
                    q.push(Node(new_x, new_y, cost));
                    
                }
                visited.insert(to_string(node.x)+"_"+to_string(node.y));
                
            }
        }
        return minCost;
        
        
    }
};
#endif

#if 0
// TLE - with priority Queue
class Solution {
private:

    vector<vector<int>> dirs = { {0,1}, {0,-1}, {1,0}, {-1,0}};
    
public:
    struct Node {
        int x, y, cost;
        Node(int _x, int _y, int _cost) : x(_x), y(_y), cost(_cost) {}
    };
    struct Comp {
        bool operator()(const Node &lh, const Node &rh) {
            return lh.cost > rh.cost;   
        }
    };
    
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int m = rowCosts.size();
        int n = colCosts.size();
        
        int x = startPos[0], y=startPos[1];
        int end_x = homePos[0], end_y = homePos[1];
        
        int minCost = INT_MAX;
        priority_queue<Node, vector<Node>, Comp> q;
        Node elem = Node(x,y,0);
        q.push(elem);
        set<string> visited;
        
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                auto node = q.top(); q.pop();
                if(node.x == end_x && node.y == end_y) {
                    minCost = min(minCost, node.cost);
                    break;
                }
                
                vector<Node> tmp;
                for(int i=0; i<dirs.size(); i++) {
                    int new_x = dirs[i][0] + node.x;
                    int new_y = dirs[i][1] + node.y;
                    if(new_x<0 || new_y<0 || new_x>=m || new_y>=n ||
                      visited.count(to_string(new_x)+"_"+to_string(new_y))>0) {
                        continue;
                    }
                    int cost = 0;
                    cost += (abs(dirs[i][0])==1) ? (node.cost + rowCosts[new_x]) :
                        (node.cost + colCosts[new_y]);
                    // q.push(Node(new_x, new_y, cost));
                    tmp.push_back(Node(new_x, new_y, cost));
                    
                }
                visited.insert(to_string(node.x)+"_"+to_string(node.y));
                for(auto elm: tmp)
                    q.push(elm);
                
            }
        }
        return minCost;
        
        
    }
};

#endif

#if 1
// Visit the bounded cells
class Solution {
private:

    
public:

    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int m = rowCosts.size();
        int n = colCosts.size();
        
        int x = startPos[0], y=startPos[1];
        int end_x = homePos[0], end_y = homePos[1];
        int minCost = 0;
        
        for(int i=end_x; i!= x; i+= end_x>x ? -1 : 1) {
            minCost += rowCosts[i];
        }
        for(int j=end_y; j!=y; j+=end_y>y ? -1: 1) {
            minCost += colCosts[j];
        }
        
        return minCost;
        
        
    }
};

#endif



