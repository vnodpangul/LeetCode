```
class SnapshotArray {
public:
unordered_map<int, map<int, int>> m; // { index : { snap_id_ : val }}
int snap_id_ = 0;
​
SnapshotArray(int length) {}
​
void set(int index, int val) {
m[index][snap_id_] = val;
}
​
int snap() {
return snap_id_++;
}
​
int get(int index, int snap_id) {
auto itr = m[index].upper_bound(snap_id);
if (itr == m[index].begin()) return 0;
return (*prev(itr)).second;
}
};
```