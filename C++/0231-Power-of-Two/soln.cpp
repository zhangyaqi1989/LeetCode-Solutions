auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && __builtin_popcount(n) == 1;
    }
};
