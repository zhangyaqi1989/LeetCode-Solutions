auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        vector<string> ans;
        char a = 'a', b = 'b';
        if (B > A) {
            swap(A, B);
            swap(a, b);
        }
        while(A) {
            int num = min(A, 2);
            ans.push_back(string(num, a));
            A -= num;
            if (B) {
                ans.push_back(string(1, b));
                --B;
            }
        }
        int i = ans.size();
        --i;
        while(B) {
            ans[i] += b;
            i -= 2;
            --B;
        }
        return accumulate(ans.begin(), ans.end(), string(""));
    }
};
