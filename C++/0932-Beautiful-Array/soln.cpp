class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> ans = {1};
        while (ans.size() < N) {
            vector<int> temp;
            for(int num : ans) {
                if (num * 2 - 1 <= N) temp.push_back(num * 2 - 1);
            }
            for(int num : ans) {
                if (num * 2 <= N) temp.push_back(num * 2);
            }
            swap(ans, temp);
        }
        return ans;
    }
};
