class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        map<vector<int>, int> m;
        m[cells] = 0;
        for(int i = 1; i <= N; ++i) {
            cells = update(cells);
            auto it = m.find(cells);
            if (it == m.end()) {
                m[cells] = i;
            } else {
                int pre = it->second;
                int period = i - pre;
                int left = (N - pre) % period;
                for(int j = 0; j < left; ++j)
                    cells = update(cells);
                break;
            }
        }
        return cells;
    }
    vector<int> update(vector<int> & cells) {
        int n = cells.size();
        vector<int> ans(n, 0);
        for(int i = 1; i < 7; ++i) {
            if (cells[i - 1] == cells[i + 1]) 
                ans[i] = 1;
        }
        return ans;
    }
};
