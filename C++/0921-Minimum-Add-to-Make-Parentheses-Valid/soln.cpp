auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// ALG
// add # of unpaired parenthese during the traverse

class Solution {
public:
    int minAddToMakeValid(string S) {
        int unpaired = 0;
        int add = 0;
        for(auto ch : S) {
            if (ch == '(') ++unpaired;
            else {
                --unpaired;
                if(unpaired == -1) {
                    ++add;
                    unpaired = 0;
                }
            }
        }
        return add + unpaired;
    }
};
