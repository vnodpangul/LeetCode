class Solution {
    map<char, vector<int>> indicesMap;
public:
    int uniqueLetterString(string s) {
        
        if(s.empty()) return 0;
        for(int i=0; i<s.size(); i++)
        {
            indicesMap[s[i]].push_back(i);
        }
        
        int sum = 0;
        for(auto eachCharIndicesList : indicesMap)
        {
            char ch = eachCharIndicesList.first;
            auto vec = eachCharIndicesList.second;
            for(int i=0; i<vec.size(); i++)
            {
                int left = (i==0) ? (vec[i] + 1) : (vec[i]-vec[i-1]); 
                int right = (i==vec.size()-1) ? (s.size()-1 - vec[i]+1) : (vec[i+1]-vec[i]);
                
                sum += (left*right);
                
            }
        }
        
        return sum;
    }
};


// abca
// 3-1

// a=[0,3]
// b=[1]
// c=[2]

