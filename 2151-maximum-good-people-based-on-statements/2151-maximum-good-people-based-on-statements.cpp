class Solution {
    vector<vector<int>> states;
    
    int applyMaskGetCount(vector<int> &roles, int mask)
    {
        int n = roles.size();
        int res = 0;
        for(int i=0; i<n; i++)
        {
            roles[i] = mask&1;
            res += roles[i];
            mask = mask>>1;
        }
        return res;
    }
    
    bool isValidRoles(vector<int> &roles)
    {
        int n = states.size();
        for(int i=0; i<n; i++)
        {
            if(roles[i]==0) continue;
            
            for(int j=0; j<n; j++)
            {
                if(states[i][j]==2) continue;
                
                if(states[i][j]!= roles[j]) return false;
                
            }
            
        }
        return true;
    }
    
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int maxGoodPerson = 0;
        states = statements;
        int total_masks = 1<<n;

        for(int mask=1; mask<total_masks; mask++)
        {
            vector<int> roles(n, 0);
            int currentGoodCount = applyMaskGetCount(roles, mask);
            
            if(isValidRoles(roles))
            {
                maxGoodPerson = max(maxGoodPerson, currentGoodCount);
            }
        }
        
        return maxGoodPerson;
    }
};

/*
n = 3
then masks are as follow:
0 0 0
0 0 1
0 1 0
0 1 1
1 0 0
1 0 1
1 1 0
1 1 1
*/