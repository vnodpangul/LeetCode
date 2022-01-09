class Solution {
    
public:
    bool isSame(const vector<int> &p1, const vector<int> &p2)
    {
        return (p1[0]==p2[0] && p1[1]==p2[1]);
    }

    double getSlope(const vector<int> &p1, const vector<int> &p2)
    {
        if ((p2[1]-p1[1]) == 0 )
            return 0;
        else if((p2[0]-p1[0]) == 0)
            return DBL_MAX;
        else
            return ((p2[1]-p1[1])*1.0)/((p2[0]-p1[0])*1.0);
    }
    
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<2) return n;
        
        set<string> visited;
        int rc=0;
        for(int i=0; i<n; i++) {
            string point_str = to_string(points[i][0]) + "_" + to_string(points[i][1]);
            if(visited.count(point_str)>0) continue;
            
            map<double, int> slopeMp; int SameCount=0; int localMax = 1;
            for(int j=i+1; j<n; j++) {
                if (isSame(points[i], points[j])) 
                    SameCount++;
                else {
                    double slope = getSlope(points[i], points[j]);
                    slopeMp[slope] ++;
                    localMax = max(localMax, slopeMp[slope]+SameCount); // consider all points with equal slope as well as same points
                }
            }
            rc = max(rc, localMax);
            visited.insert(point_str);
            
        }
        return rc+1; // An extra count for start point
    }
};

