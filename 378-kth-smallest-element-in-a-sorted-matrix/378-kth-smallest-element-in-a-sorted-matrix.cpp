// Ref: https://www.youtube.com/watch?v=dpsp1hP6P-U

class Solution {
public:
    
    int countElemsLessThanEqual(vector<vector<int>>& matrix, int elem) {
        int m = matrix.size();
        int n = matrix[0].size();
        int count = 0;
        for(int i=0; i<m; i++) {
            for(int j=n-1; j>=0; j--) { // Start searching from last column for every row
                if(matrix[i][j]<=elem) {
                    count += j+1;
                    break;  // Break to move on to next row for counting
                }
            }
        }

        return count;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        if(m==0) return -1;
        int n = matrix[0].size();
        
        int low = matrix[0][0], high=matrix[m-1][n-1];
        while(low<high) {
            int mid = low + (high-low)/2;
            int count = countElemsLessThanEqual(matrix, mid);
            if(count < k)
                low = mid+1;
            else
                high = mid;
        }
        
        return low;
    }
};

