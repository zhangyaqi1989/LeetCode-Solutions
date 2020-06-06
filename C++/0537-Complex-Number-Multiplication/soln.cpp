class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ra, ia, rb, ib;
        stringstream aa(a), bb(b), ans;
        char buff;
        aa >> ra >> buff >> ia >> buff;
        bb >> rb >> buff >> ib >> buff;
        ans << (ra * rb - ia * ib) << '+' << (ra * ib + rb * ia) << "i";
        return ans.str();
    }
};
