class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int carry = 0;
        int na = a.length(), nb = b.length();
        int ia = na - 1, ib = nb - 1;
        while(ia >= 0 || ib >= 0 || carry) {
            int va = ia >= 0 ? a[ia] - '0' : 0;
            int vb = ib >= 0 ? b[ib] - '0' : 0;
            if (ia >= 0) --ia;
            if (ib >= 0) --ib;
            int v = va + vb + carry;
            carry = v / 2;
            ans += v % 2 ? "1" : "0";
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
