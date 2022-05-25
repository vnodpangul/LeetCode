class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> res;
        res.resize(numRows, vector<int>());
        
        int count = 0;
        
        if(numRows == 0) return res;
        res[count].push_back(1);
        if(numRows<2) return res;

        ++count;
        for(int i=0; count<numRows && i<=count; i++) {
        
            if(i == 0 || (i==count))
            {
                res[count].push_back(1);
            }else {
                
                int sum = 0;
                sum = res[count-1][i-1] +  res[count-1][i];
                res[count].push_back(sum);
            }
            if(i==count) {
                count++;
                i=-1;
            }
            
        }
        return res;
        
    }
};