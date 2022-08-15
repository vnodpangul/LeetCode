class Solution {
    
    struct Point
    {
        int x, h;
        bool isStart;
        Point(int _x, int _h, bool _val=true):
            x(_x), h(_h), isStart(_val) {}      
    };
    
    vector<Point> pts;
    map<int, int> q; // maxHeap using sorted map
public:
    static bool compFunc(Point &p1, Point &p2)
    {
        /*
        if(p1.isStart && p2.isStart) return p1.h > p2.h ;         // In increasing order of heights
        else if(!p1.isStart && !p2.isStart) return p1.h < p2.h ;  // In descending order of heights
        else
            return p1.isStart ? p1.h : p2.h;                      // If mix, return start point first
        */
        return (p1.x < p2.x) || ( p1.x==p2.x && p1.h <p2.h);
    }
    
    vector<vector<int>> getSkyline(vector<vector<int>>& bldgs) { 
        for(int i=0; i<bldgs.size(); i++)
        {
            Point p1(bldgs[i][0], -bldgs[i][2], true);
            pts.push_back(p1);
            
            Point p2(bldgs[i][1], bldgs[i][2], false);
            pts.push_back(p2);
        }
        sort(pts.begin(), pts.end(), compFunc);

        vector<vector<int>> res;
        int n = pts.size();
        
        q[0] = 1; // 0 point occured once
        int prevMaxH = 0;
        for(int i=0; i<n; i++)
        {
            auto p = pts[i];
            int h = p.h;
            int x = p.x;
            
            if(p.isStart)
            {
                q[-h]++;
            }else {
                q[h]--;
                if(q[h]==0) {
                    q.erase(h);
                }
            }
            auto it = q.rbegin(); 
            int currentMaxH = it->first;
            if(currentMaxH != prevMaxH)
            {
                res.push_back({x, it->first});
                prevMaxH = currentMaxH;
            }
            
        }
        return res;
    }
};
       