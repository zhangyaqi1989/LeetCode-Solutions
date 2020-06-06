class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> ans;
        unordered_map<char, int> counter;
        for(auto ch : s) {
            ++counter[ch];
        }
        int odds = 0;
        string half = "", mid = "";
        for(auto & p : counter) {
            if (p.second % 2 == 1) {
                ++odds;
                if (odds > 1) return ans;
                mid = p.first;
            }
            half += string(p.second / 2, p.first);
        }
        vector<string> permus;
        // cout << half << endl;
        string init(half);
        do {
            permus.push_back(half);
            next_permutation(half.begin(), half.end());
        } while (half != init);
        for(auto permu : permus) {
            string r(permu);
            reverse(r.begin(), r.end());
            ans.push_back(permu + mid + r);
        }
        return ans;
        
    }
};
