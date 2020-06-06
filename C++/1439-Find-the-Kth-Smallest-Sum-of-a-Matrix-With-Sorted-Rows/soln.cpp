class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int h = mat.size(), w = mat[0].size();
        int lo = 0;
        vector<int> cur(h, 0);
        for(auto & row : mat) {
            lo += row[0];
        }
        priority_queue<pair<int, vector<int>>> pq;
        pq.push({-lo, cur});
        set<vector<int>> visited;
        visited.insert(cur);
        while(!pq.empty()) {
            auto [sum, cur] = pq.top();
            pq.pop();
            sum = -sum;
            // cout << sum << endl;
            // for(int i : cur) cout << i << " ";
            // cout << endl;
            if(--k == 0) return sum;
            for(int r = 0; r < h; ++r) {
                if(cur[r] + 1 < w) {
                    cur[r] += 1;
                    if(visited.find(cur) == visited.end()) {
                        vector<int> nxt(cur);
                        visited.insert(nxt);
                        pq.push({-(sum - mat[r][cur[r] - 1] + mat[r][cur[r]]), nxt});

                    }
                    cur[r] -= 1;
                }
            }
        }
        return -1;
    }
};
