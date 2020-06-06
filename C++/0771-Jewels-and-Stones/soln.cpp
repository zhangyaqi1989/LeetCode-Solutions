class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> jewels(J.begin(), J.end());
        int cnt = 0;
        for(char ch : S) {
            if (jewels.find(ch) != jewels.end()) ++cnt;
        }
        return cnt;
    }
};
