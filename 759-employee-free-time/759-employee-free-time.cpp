/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        struct comp {
            bool operator()(Interval &l, Interval &r)
            {
                return l.start > r.start;
            }
        };
        priority_queue<Interval, vector<Interval>, comp> pq;
        for(auto &elm : schedule) {
            for(auto e: elm) {
                pq.push(e);
            }
        }
        
         vector<Interval> res;
        int end = pq.top().end; pq.pop();
        while(!pq.empty()) {
            auto elm = pq.top(); pq.pop();
            if(elm.start>end) {
                res.push_back(Interval(end, elm.start));
                end = elm.end;
            }else {
                end = max(end, elm.end);
            }
        }
        
        return res;
    }
};



// [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]

// [
//  [[1,2],[5,6]],
//  [[1,3]],[[4,10]]
//  ]
//  ---
//  [[1,2],[[1,3]],[[4,10]],[5,6]]
//  end = 10
//  curr = [4,10]
     

//         int end = pq.poll().end; //initial end time
//         List<Interval> result = new ArrayList<>();
//         while(!pq.isEmpty()) {
//             Interval curr = pq.poll();
//             if(curr.start > end) { //no overlap
//                 result.add(new Interval(end, curr.start));
//                 end = curr.end;
//             }else { //overlap
//                 end = Math.max(end, curr.end);
//             }
//         }