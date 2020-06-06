class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        vector<int> parents(N);
        iota(parents.begin(), parents.end(), 0);
        sort(connections.begin(), connections.end(), [] (const vector<int> & a, const vector<int> & b) {
            return a[2] < b[2];
        });
        int min_cost = 0, cnt = 0;
        for(const auto & c : connections) {
            int u = c[0] - 1, v = c[1] - 1;
            int ru = Find(u, &parents), rv = Find(v, &parents);
            if (ru != rv) {
                parents[ru] = rv;
                min_cost += c[2];
                if(++cnt == N - 1) return min_cost;
            }
        }
        return cnt == N - 1 ? min_cost : -1;
    }
    
private:
    int Find(int x, vector<int> * parents) {
        return (parents->at(x) == x) ? x : parents->at(x) = Find(parents->at(x), parents);
    }
};
