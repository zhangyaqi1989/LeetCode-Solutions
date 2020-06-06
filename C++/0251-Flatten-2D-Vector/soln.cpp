class Vector2D {
    vector<int> data;
    int cnt;
    int idx;
public:
    Vector2D(vector<vector<int>> v) {
        cnt = 0;
        idx = 0;
        for(auto & lst : v) {
            for(int num : lst) {
                data.push_back(num);
                ++cnt;
            }
        }
        
    }
    
    int next() {
        return data[idx++];
    }
    
    bool hasNext() {
        return idx < cnt;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
