class Solution {
public:
    int confusingNumberII(int N) {
        string bads = "23457";
        int goods [] = {0, 1, 6, 8, 9};
        ++N;
        string string_N = to_string(N);
        int n = string_N.length();
        int ans = 0;
        for(int i = 1; i < n; ++i) ans += 4 * pow(5, i - 1);
        for(int i = 0; i < n; ++i) {
            char ch_d = string_N[i];
            int start = (i == 0 ? 1 : 0);
            int d = ch_d - '0';
            for(int j = start; j < 5; ++j) {
                if (goods[j] >= d) break;
                ans += pow(5, n - i - 1);
            }
            if (bads.find(ch_d) != string::npos) break;
        }
        return ans - count_sames(1, N - 1);
        
    }
    
    vector<string> generate_sames(int n) {
        vector<string> ans;
        if (n & 1 == 1) {
            ans.push_back("0");
            ans.push_back("1");
            ans.push_back("8");
        } else {
            ans.push_back("");
        }
        string pairs[5] = {"00", "11", "88", "96", "69"};
        while (n > 1) {
            vector<string> temp;
            n -= 2;
            int start = (n >= 2) ? 0 : 1;
            for(int i = start; i < 5; ++i) {
                string first = pairs[i].substr(0, 1), last = pairs[i].substr(1);
                for(string item : ans) temp.push_back(first + item + last);
            }
            swap(temp, ans);
        }
        return ans;
    }
    
    int count_sames(int lo, int hi) {
        int L = to_string(lo).length(), H = to_string(hi).length();
        int cnt = 0;
        for(int i = L; i <= H; ++i) {
            vector<string> lst = generate_sames(i);
            for(string s : lst) {
                long long num = stoll(s);
                if (lo <= num && num <= hi) ++cnt;
            }
        }
        return cnt;
    }
};
