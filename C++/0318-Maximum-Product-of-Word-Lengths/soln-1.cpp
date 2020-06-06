class Solution {
public:
    int maxProduct(vector<string>& words) {
        map<int, int> m;
        for(string word : words) {
            int temp = 0;
            for(char ch : word) {
                temp |= (1 << (ch - 'a'));
            }
            if (word.length() > m[temp]) m[temp] = word.length();
        }
        int ans = 0;
        for(auto & p1 : m) {
            for(auto & p2 : m) {
                if (!(p1.first & p2.first)) 
                    ans = max(ans, p1.second * p2.second);
            }
        }
        return ans;
    }
};
