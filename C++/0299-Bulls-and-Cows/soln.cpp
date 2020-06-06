class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        unordered_map<int, int> m;
        for(int i = 0; i < secret.size(); ++i)
        {
            if(secret[i] == guess[i]) bulls++;
            m[secret[i]]++;
        }
        for(auto digit : guess)
        {
            
            if(m[digit]-- > 0) cows++;
        }
        cows -= bulls;
        string ans = to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};