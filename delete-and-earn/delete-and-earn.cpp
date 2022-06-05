class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        set<int> sorted_arr;
        for(auto n: nums) {
            mp[n]++;
            sorted_arr.insert(n);
        }
        
        int earn1=0, earn2=0, i=0, prev = 0;
        for(auto n : sorted_arr) {
            if(i>0 && n == prev+1)
            {
                int tmp =earn2;
                earn2 = max(earn1+(n * mp[n]), earn2);
                earn1 = tmp;
                
            }else {
                
                int tmp = earn2;
                earn2 = earn2 + n*mp[n];
                earn1 = tmp;
            }
            i++;
            prev = n;
        }
            
        return earn2;
        
        
        
    }
};