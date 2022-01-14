class Solution {
public:
    int getCountLessThanEqual(int m, int n, int elem, int k) {
        int count = 0;
        for(int i=1, j=n; i<=m; i++) {
            while(j>=1 && i*j>elem) j--;
            if(j==0) break;
            count += j;
            if(count>k) break;
        }
        return count;
    }
    
    int findKthNumber(int m, int n, int k) {
        if(m==0) return -1;
        
        int low = 1, high = m*n;
        while(low<high) {
            int mid = low + (high-low)/2;
            int count = getCountLessThanEqual(m, n, mid, k);
            if(count<k)
                low = mid+1;
            else
                high = mid;
        }
        return low;
        
        
    }
};