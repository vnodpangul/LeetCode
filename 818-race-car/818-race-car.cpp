class Solution {
    struct Node {
        long pos, speed, moves;
        Node(int p, int s, int m) : pos(p), speed(s), moves(m) {}
    };
    
    set<string> visited;
    queue<Node> q;
public:
    int racecar(int target) {
        int p = 0, s = 1, m = 0;
        q.push(Node(p,s,m));
        while(!q.empty()) {
            auto node = q.front(); q.pop();
            if(node.pos == target)
                return (int) node.moves;
            auto key = to_string(node.pos)+"_"+to_string(node.speed);
            // cout<<key<<endl;
            if(visited.count(key)>0)
                continue;
            
            visited.insert(key);
            q.push(Node(node.pos+node.speed, node.speed*2, node.moves+1));
            if( ((node.speed+node.pos)>target && node.speed>0) ||
                ((node.speed+node.pos)<target && node.speed<0)
              )
            {
                int pos = node.pos;
                int speed = node.speed>0 ? -1 : 1;
                int moves = node.moves+1;
                q.push(Node(pos, speed, moves));
            }
            
        }
        return 0;
    }
};