class Solution {
public:
    string reorganizeString(string S) {
        int chars[26] = {0};
        for(char ch : S) ++chars[ch - 'a'];
        priority_queue<pair<int, char>> pq;
        for(int i = 0; i < 26; ++i) {
            if (chars[i] != 0) {
                pq.push({chars[i], i + 'a'});
            }
        }
        int i = 0;
        char prev = 'A';
        string ans = "";
        while (i < S.length()) {
            auto top = pq.top();
            pq.pop();
            if (top.second == prev) {
                if (pq.empty()) return "";
                auto second = pq.top();
                pq.pop();
                --second.first;
                prev = second.second;
                if (second.first != 0) pq.push(second);
            } else {
                --top.first;
                prev = top.second;
            }
            ans += prev;
            if (top.second != 0) pq.push(top);
            ++i;
        }
        return ans;
    }
};
