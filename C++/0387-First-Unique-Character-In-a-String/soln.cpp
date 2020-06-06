class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int, int>> arr(26, {-1, -1});
        for(int i = 0; i < s.size(); ++i)
        {
            int idx = s[i] - 'a';
            if(arr[idx].first == -1)
            {
                arr[idx].first = i;
                arr[idx].second = i;
            } else
                arr[idx].second = i;
        }
        int ans = s.size();
        for(auto item : arr)
        {
            if(item.first != -1 && item.first == item.second && item.first < ans)
                ans = item.first;
        }
        if(ans == s.size()) return -1;
        return ans;
    }
};
