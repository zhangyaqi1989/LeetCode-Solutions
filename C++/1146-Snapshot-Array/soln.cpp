class SnapshotArray {
public:
    vector<vector<pair<int, int>>> nums;
    int snap_id;
    SnapshotArray(int length) {
        vector<pair<int, int>> temp;
        temp.push_back({-1, 0});
        for(int i = 0; i < length; ++i) {
            nums.push_back(temp);
        }
        snap_id = 0;
    }
    
    void set(int index, int val) {
        nums[index].push_back({snap_id, val});
    }
    
    int snap() {
        ++snap_id;
        return snap_id - 1;
    }
    
    int get(int index, int snap_id) {
        int i = lower_bound(nums[index].begin(), nums[index].end(), make_pair(snap_id + 1, -1)) - nums[index].begin() - 1;
        return nums[index][i].second;
    }
};


/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
