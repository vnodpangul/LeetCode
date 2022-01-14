class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m==0) return false;
        int n = matrix[0].size();
        
        int low = 0, high= m*n-1;
        while(low<=high) {
            int mid = low + (high-low)/2;
            
            int x = mid/n; int y = mid%n; // n = No. of Cols
            if(matrix[x][y] == target) {
                return true;
            }else if(matrix[x][y]<target) {
                low = mid+1;
            }else {
                high = mid-1;
            }
        }
        return false;
    }
};

// low = 0, high=11 || m=3, n=4
//     mid = 0 + (11-0)/2 = 5 --> i, j ==> 5/4, 5%4 ==> 1,1
    