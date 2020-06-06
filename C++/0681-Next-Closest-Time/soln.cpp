class Solution {
public:
    string nextClosestTime(string time) {
        int idx = time.find(":");
        string h = time.substr(0, idx);
        string m = time.substr(idx + 1);
        vector<bool> digits(10, false);
        for(char ch : h) digits[ch - '0'] = true;
        for(char ch : m) digits[ch - '0'] = true;
        int cur = stoi(h) * 60 + stoi(m);
        int mn_diff = 2000;
        string ans = "";
        char temp[6];
        for(int num = 0; num < 1440; ++num) {
            int hh = num / 60;
            int mm = num % 60;
            sprintf(temp, "%02d:%02d", hh, mm);
            string time_str(temp);
            bool valid = true;
            for(char ch : time_str) {
                if (ch == ':') continue;
                if (!digits[ch - '0']) valid = false;
            }
            if (valid) {
                int diff = (cur < num) ? (num - cur) : (1440 + num - cur);
                if (diff < mn_diff) {
                    mn_diff = diff;
                    ans.assign(temp);
                }
            }
        }
        return ans;
    }
};
