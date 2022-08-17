class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> rows(9), cols(9), kbox(9);
        
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                
                if(board[i][j] == '.')
                    continue;
                
                int num = board[i][j]-'0';
                int idx = (i/3)*3 + (j/3);
                if(rows[i].count(num) || cols[j].count(num) || kbox[idx].count(num))
                    return false;
                
                rows[i].insert(num);
                cols[j].insert(num);
                kbox[idx].insert(num);
            }
        }
        
        return true;
    }
};