class FileSharing {
public:
    FileSharing(int m) {
        m_ = m;
        const int kN = 10005;
        for(int id = 1; id < kN; ++id) free_ids_.insert(id);
        owners_.resize(m_ + 1);
        chunks_.resize(kN);
    }
    
    int join(vector<int> ownedChunks) {
        int id = *free_ids_.begin();
        free_ids_.erase(free_ids_.begin());
        for(int chunk : ownedChunks) {
            owners_[chunk].insert(id);
            chunks_[id].insert(chunk);
        }
        return id;
    }
    
    void leave(int userID) {
        free_ids_.insert(userID);
        for(int chunk : chunks_[userID]) {
            owners_[chunk].erase(userID);
        }
        chunks_[userID].clear();
    }
    
    vector<int> request(int userID, int chunkID) {
        vector<int> ids(owners_[chunkID].begin(), owners_[chunkID].end());
        if(!ids.empty()) {
            owners_[chunkID].insert(userID);
            chunks_[userID].insert(chunkID);            
        }
        return ids;
    }
    
    
private:
    int m_;
    set<int> free_ids_;
    vector<set<int>> owners_; // map chuck to set of owners
    vector<set<int>> chunks_; // map owner to set of chunks
};

/**
 * Your FileSharing object will be instantiated and called as such:
 * FileSharing* obj = new FileSharing(m);
 * int param_1 = obj->join(ownedChunks);
 * obj->leave(userID);
 * vector<int> param_3 = obj->request(userID,chunkID);
 */
