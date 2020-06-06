class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> kinds(candies.begin(), candies.end());
        int total = candies.size(), nkinds = kinds.size();
        return min(total / 2, nkinds);
    }
};
