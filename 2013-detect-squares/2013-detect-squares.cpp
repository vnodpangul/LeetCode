class DetectSquares {
    vector<vector<int>> pts;
    int dp[3000][3000]  = {};
    
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        dp[x][y]++;
        pts.push_back(point);
    }
    
    int count(vector<int> point) {
        int res = 0;
        int x1 = point[0], y1=point[1];
        for(auto p : pts) {
            int x3 = p[0], y3=p[1];
            if(abs(x3-x1)==0 || abs(x3-x1)!=abs(y3-y1) ) {
                continue;
            }
            res += dp[x1][y3] * dp[x3][y1];
        }
        return res;
        
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */