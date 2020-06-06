class Solution {
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        unordered_set<string> ans;
        int n = tiles.length();
        do {
            for(int i = 0; i < (1 << n); ++i) {
                string temp = "";
                for(int j = 0; j < n; ++j) {
                    if (i & (1 << j)) temp += tiles[j];
                }
                ans.insert(temp);
            }
        } while (next_permutation(tiles.begin(), tiles.end()));
        return ans.size() - 1;
    }
};
