class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        for(auto & book : bookings) {
            int i = book[0], j = book[1], k = book[2];
            counter[i] += k;
            counter[j + 1] -= k;
        }
        int cnt = 0;
        vector<int> ans;
        for(int i = 1; i <= n; ++i) {
            cnt += counter[i];
            ans.push_back(cnt);
        }
        return ans;
    }
    
private:
    map<int, int> counter;
};
