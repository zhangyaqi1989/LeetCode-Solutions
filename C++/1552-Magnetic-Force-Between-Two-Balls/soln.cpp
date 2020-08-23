class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int lo = 0, hi = position.back() - position.front();
        while(lo < hi) {
            int mid = hi - (hi - lo) / 2;
            if(Valid(position, m, mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
    
    
private:
    bool Valid(const vector<int> & position, int m, int d) {
        int pre = -1e9;
        int cnt = 0;
        for(int p : position) {
            if(p - pre >= d) {
                pre = p;
                if(++cnt == m) return true;
            }
        }
        return false;
    }
};
