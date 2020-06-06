class Solution {
public:
    string maskPII(string S) {
        auto idx = S.find('@');
        if (idx != string::npos) {
            transform(S.begin(), S.end(), S.begin(), ::tolower);
            string name = S.substr(0, idx);
            name = name[0] + string(5, '*') + name.back();
            return name + S.substr(idx);
        } else {
            string nums = "";
            for(char ch : S) {
                if (isdigit(ch)) nums += ch;
            }
            int n = nums.length();
            if (n == 10) return "***-***-" + nums.substr(n - 4);
            else {
                return "+" + string(n - 10, '*') + "-***-***-" + nums.substr(n - 4);
            }
        }
    }
};
