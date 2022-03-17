class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows, cols;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j]==1) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        
        int medRow = rows[rows.size()/2];
        sort(cols.begin(), cols.end());
        int medCol = cols[cols.size()/2];
        
        return getMindistance(rows, medRow) + getMindistance(cols, medCol);
        
    }
    
    int getMindistance(vector<int> &vec, int med) {
        int dist = 0;
        for(auto p : vec) {
            dist += abs(med-p);
        }
        return dist;
    }
};

// [[1,0,0,0,1],
//  [0,0,0,0,0],
//  [0,0,1,0,0]]
 
// rows = |0, 0, 2 |
// cols = |0, 4, 2 |