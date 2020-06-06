class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> pairs;
        for(int num : arr) {
            int cnt = 0;
            int temp = num;
            while (temp) {
                cnt += temp % 2;
                temp /= 2;
            }
            pairs.emplace_back(cnt, num);
        }
        sort(pairs.begin(), pairs.end());
        vector<int> ans;
        for(const auto & p : pairs) {
            ans.push_back(p.second);
        }
        return ans;
    }
};
