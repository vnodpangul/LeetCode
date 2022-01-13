class SnapshotArray {
public:
    SnapshotArray(int length) {
    }
    
    void set(int index, int val) {
        snapMp[index][snapCount] = val;
    }
    
    int snap() {
        return snapCount++;
    }
    
    int get(int index, int snap_id) {
        auto it = snapMp[index].upper_bound(snap_id);
        if(it == snapMp[index].begin()) return 0;
        return prev(it)->second;
    }
private:
    int snapCount = 0;
    unordered_map<int, map<int, int>> snapMp; //<idx, <snapId, val>>
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */