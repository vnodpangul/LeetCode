class Solution {
public:
    bool isValid(int x, int y)
    {
        if(x<0|| x>=m || y<0 || y>=n) return false;
        return true;
    }
    
    void DFS(int x, int y, vector<vector<bool>> &visited)
    {
        if(!isValid(x,y) || visited[x][y] || board[x][y]!='E') return;
        
        int M_count = 0;
        visited[x][y]=true;
        board[x][y] = 'B';
        
        for(auto dir : dirs)
        {
            int new_x = x + dir[0];
            int new_y = y + dir[1];
            if(!isValid(new_x, new_y) || visited[new_x][new_y]) continue;
            if(board[new_x][new_y]=='M') M_count++;
        }
        if(M_count>0){ 
            board[x][y] = M_count+'0';
            return;
        }
        else {
            for(auto dir : dirs)
            {
                DFS(x+dir[0], y+dir[1], visited);
            }
        }
    }
        
    void helper(int x, int y, vector<vector<bool>> &visited)
    {
        if(!isValid(x,y)) return;
        
        if(board[x][y] == 'M') {
            board[x][y] = 'X';
            return;
        }
        
        DFS(x, y, visited);
 
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size();
        n = board[0].size();
        this->board = board;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        helper(click[0], click[1], visited);
        return this->board;
    }
private:
    int m,n;
    vector<vector<char>> board;
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}, 
                                {1,-1}, {-1,-1}, {1,1}, {-1,1}};
    queue<pair<int, int>> q;
};


#if 0

[
 ["E","E","E","E","E"],
 ["E","E","M","E","E"],
 ["E","E","E","E","E"],
 ["E","E","E","E","E"]
]
<3,0>


'M'--> 'X'
'E' --> 
    No 'M'
        'B' & Recur to find all nearby 'E'
    else if mine is near
        change it to count '1' to '8'

board[x][y]='B';
visited[x][y]='true';
res += DFS(x,y, board, mcount);
if(res>0)
    board[x][y] = res;

[
 ["E","E","E","E","E"],
 ["E","E","M","E","E"],
 ["E","E","E","E","E"],
 ["E","E","E","E","E"]
]

[["B","1","1","1","B"],
 ["B","1","M","1","B"],
 ["B","1","1","1","B"],
 ["B","B","B","B","B"]]
 
[["B","1","E","1","B"],
 ["B","1","M","1","B"],
 ["B","1","1","1","B"],
 ["B","B","B","B","B"]]
#endif