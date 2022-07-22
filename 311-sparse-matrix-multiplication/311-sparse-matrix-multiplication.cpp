/*
Brute Force
TC: O(n*k*m)
SC: O(1)
*/

#if 0
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        
        int m = mat1.size();
        int kk = mat1[0].size();
        int n = mat2[0].size();
        
        vector<vector<int>> res(m, vector<int>(n,0));
        for(int i=0; i<m; i++)
        {
            for(int k=0; k<kk; k++)
            {
                if(mat1[i][k]!=0)
                {
                    for(int j=0; j<n; j++)
                    {
                        res[i][j] += mat1[i][k] * mat2[k][j];
                        
                    }
                }                
            }

        }
        return res;
    }
};

#endif

#if 1
class Solution {
    using Pair = pair<int, int>;
public:
    vector<vector<Pair>> getCompressedMat(vector<vector<int>> &sm)
    {
        vector<vector<Pair>> res(sm.size(), vector<Pair>());
        for(int i=0; i<sm.size(); i++)
        {
            for(int j=0; j<sm[0].size(); j++)
            {
                if(sm[i][j]!=0)
                {
                    res[i].push_back(make_pair(sm[i][j],j));
                }
            }
        }
        return res;
    }
    
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size();
        int k = mat1[0].size();
        int n = mat2[0].size();
        
        vector<vector<int>> res(m, vector<int>(n,0));
        auto cmat1 = getCompressedMat(mat1);
        auto cmat2 = getCompressedMat(mat2);
        
        for(int i=0; i<cmat1.size(); i++)
        {
            auto val_col_vec = cmat1[i];
            for(auto &elem : val_col_vec)
            {
                int row1 = i, col1 = elem.second, val1 = elem.first;
                for(auto elem2: cmat2[col1])
                {
                    int col2 = elem2.second, val2 = elem2.first;
                    res[row1][col2] += (val1*val2);
                } 
            }
        }
        return res;
    }
};
#endif