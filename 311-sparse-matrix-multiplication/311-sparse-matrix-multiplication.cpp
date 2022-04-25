class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int r1 = mat1.size(), c1 = mat1[0].size(), r2=mat2.size(), c2=mat2[0].size();
        
        vector<vector<int>> mat2Cols(r2, vector<int>());
        for(int i=0; i<r2; i++) {
            for(int j=0; j<c2; j++) {
                if(mat2[i][j] != 0) 
                    mat2Cols[i].push_back(j);
            }
        }
        
        vector<vector<int>> res(r1, vector<int>(c2, 0));
        for(int i=0; i<r1; i++) {
            for(int j=0; j<c1; j++) {
                if(mat1[i][j] != 0) {
                    
                    for(int k: mat2Cols[j]) 
                        res[i][k] += (mat1[i][j]*mat2[j][k]);
                }
            }
        }
        
        return res;
    }
};