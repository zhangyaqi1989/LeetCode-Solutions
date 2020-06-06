class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k == 0) return s;
        int counter[26] = {0};
        for(char ch : s) ++counter[ch - 'a'];
        priority_queue<pair<int, char>> pq;
        for(char ch = 'a'; ch <= 'z'; ++ch) {
            if (counter[ch - 'a']) pq.push({counter[ch - 'a'], ch});
        }
        string ans;
        const int n = s.length();
        vector<pair<int, char>> temp;
        while (ans.length() < n) {
            for(int i = 0; i < k; ++i) {
                if (ans.length() == n) return ans;
                if (pq.empty()) return "";
                int cnt;
                char ch;
                tie(cnt, ch) = pq.top();
                pq.pop();
                ans += ch;
                if (--cnt > 0) temp.emplace_back(cnt, ch);
            }
            while(!temp.empty()) {
                pq.push(temp.back());
                temp.pop_back();
            }
        }
        return ans;
    }
};
