auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        vector<pair<char, int>> ps = encode(S);
        int cnt = 0;
        for(auto & word : words) {
            auto pw = encode(word);
            if(pw.size() != ps.size()) continue;
            int flag = true;
            for(int i = 0; i < ps.size(); ++i) {
                if(ps[i].first != pw[i].first || (pw[i].second < ps[i].second && ps[i].second < 3) || pw[i].second > ps[i].second) {
                    flag = false;
                    break;
                } 
            }
            if (flag) ++cnt;
        }
        return cnt;
    }
    
    vector<pair<char, int>> encode(string S) {
        vector<pair<char, int>> ps;
        int i = 0;
        S += '#';
        for(int j = 0; j < S.length(); ++j) {
            if(S[j] != S[i]) {
                ps.push_back({S[i], j - i});
                i = j;
            }
        }
        return ps;
    }
};
