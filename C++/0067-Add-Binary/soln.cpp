class Solution {
public:
    string addBinary(string a, string b) {
        auto ita = a.rbegin();
        auto itb = b.rbegin();
        string ans = "";
        int carry = 0;
        int vala, valb, val;
        while (carry != 0 || ita != a.rend() || itb != b.rend())
        {
            vala = ita != a.rend() ? (*ita == '1' ? 1 : 0) : 0;
            valb = itb != b.rend() ? (*itb == '1' ? 1 : 0) : 0;
            val = vala + valb + carry;
            carry = val / 2;
            val = val % 2;
            ita = ita == a.rend() ? a.rend() : ++ita;
            itb = itb == b.rend() ? b.rend() : ++itb;
            ans = (val == 1 ? "1" : "0") + ans;
        }
        return ans;
    }
};