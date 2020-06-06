class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int> m;
        int count = 0;
        for(auto ch : tasks) {
            m[ch] ++;
            count = max(count, m[ch]);
        }
        int ans = (n + 1) * (count - 1);
        for (auto & pair : m) {
            if (pair.second == count)
                ans ++;
        }
        return max(ans, (int) tasks.size());
    }
};
