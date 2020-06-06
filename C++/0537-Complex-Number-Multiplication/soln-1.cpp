class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        pair<int, int> ca = parse(a), cb = parse(b);
        int real = ca.first * cb.first - ca.second * cb.second;
        int imag = ca.second * cb.first + ca.first * cb.second;
        string ans = to_string(real) + "+" + to_string(imag) + "i";
        return ans;
    }
    
    pair<int, int> parse(string s) {
        int idx = s.rfind('+');
        int real = stoi(s.substr(0, idx));
        int imag = stoi(s.substr(idx + 1, s.length() - 1 - idx));
        return {real, imag};
    }
};
