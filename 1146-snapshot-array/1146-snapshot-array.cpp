class SnapshotArray {
    map<int, map<int, int>> cache;
    int snapId = 0;
    int maxLen = 0;
public:
    SnapshotArray(int length) {
        maxLen = length;
    }
    
    void set(int index, int val) {
        cache[index][snapId] = val;
    }
    
    int snap() {
        snapId++;
        return snapId-1;
    }
    
    int get(int index, int snap_id) {
        auto it = cache[index].upper_bound(snap_id);
        if(it == cache[index].begin()) return 0;
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

// map[index][snap_id] map;

// map<int, map<int, int>> cache;

