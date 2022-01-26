class Solution {
public:
    void DFS(vector<vector<int>>& board, int m, int n, int i, int j)
    {
        int liveCount = 0;
        for(int k=0; k<dirs.size(); k++) {
            int new_x = dirs[k][0] + i;
            int new_y = dirs[k][1] + j;
            if(new_x<0 || new_x==m || new_y<0 || new_y==n) continue;
            
            if(board[new_x][new_y]==1 || board[new_x][new_y]==-1) liveCount++;
        }
        
        if(board[i][j]==0 && liveCount==3) {
            board[i][j]=2;
        }else if(board[i][j]==1 && (liveCount>3 || liveCount<2) ) {
            // cout<<"Dying \n";
            board[i][j]= -1;
        }
        
        
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                DFS(board, m, n, i, j);
            }
        }
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j]== -1) board[i][j]=0;
                else if(board[i][j]==2) board[i][j]=1;
            }
        }
        
    }
private:
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}, 
                                {1,1}, {-1,1}, {1,-1}, {-1,-1}};
};

// 1--> 1 (2or3 liveNbrs)
// 1--> 0 (Less than 2)
// 1--> 0 (More than 3)
// 0--> 1 (live==3)  (no.2) means previous 0
