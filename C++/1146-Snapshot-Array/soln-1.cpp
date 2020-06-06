class SnapshotArray {
public:
    SnapshotArray(int length): records_(length), snap_id_(0) {
        for(int i = 0; i < length; ++i) {
            records_[i].emplace_back(-1, 0);
        }
        
    }
    
    void set(int index, int val) {
        unsaved_[index] = val;
    }
    
    int snap() {
        for(const auto & p : unsaved_) {
            int idx, val;
            tie(idx, val) = p;
            if (records_[idx].back().second != val) {
                records_[idx].emplace_back(snap_id_, val);
            }
        }
        unsaved_.clear();
        return snap_id_++;
    }
    
    int get(int index, int snap_id) {
        auto it = lower_bound(records_[index].begin(), records_[index].end(), make_pair(snap_id + 1, -1));
        return prev(it)->second;
    }
private:
    vector<vector<pair<int, int>>> records_; // (snap_id, val) pairs
    int snap_id_;
    unordered_map<int, int> unsaved_;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
