class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        // [idi, ratingi, veganFriendlyi, pricei, distancei]
        vector<pair<int, int>> pairs;
        for(const auto & rest : restaurants) {
            int id = rest[0], r = rest[1], v = rest[2], p = rest[3], d = rest[4];
            if (veganFriendly == 1 && v == 0) continue;
            if (p <= maxPrice && d <= maxDistance) pairs.emplace_back(r, id);
        }
        sort(pairs.rbegin(), pairs.rend());
        vector<int> ans;
        for(const auto & p : pairs) {
            ans.push_back(p.second);
        }
        return ans;
    }
};
