class Solution {
public:
    int numRabbits(vector<int>& answers) {
        // how many other rabbits have the same color as them
        if (answers.empty()) return 0;
        sort(answers.begin(), answers.end());
        int ans = 0, cur = answers[0], cnt = 0;
        answers.push_back(1000);
        for(auto x : answers) {
            if (x > cur) {
                // cout << cnt << " " << cur << endl;
                int unit = cur + 1;
                ans += (unit) * ((cnt + cur) / unit);
                cnt = 1;
                cur = x;
            } else {
                ++cnt;
            }
        }
        return ans;
    }
};
