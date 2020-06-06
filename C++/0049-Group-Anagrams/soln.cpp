class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> primes;
        int num = 2;
        while (primes.size() != 26)
        {
            if(isPrime(num)) primes.push_back(num);
            ++num;
        }
        unordered_map<long long, vector<string>> ans;
        for(auto s : strs)
        {
            ans[toNum(s, primes)].push_back(s);
        }
        vector<vector<string>> anagrams;
        for(auto item : ans)
        {
            vector<string> anagram(item.second.begin(), item.second.end());
            anagrams.push_back(anagram);
        }
        return anagrams;
    }
    
    bool isPrime(int num)
    {
        for(int i = 2; i < num; ++i)
            if(num % i == 0) return false;
        return true;
    }
    
    int long long toNum(string s, vector<int>& primes)
    {
        long long ans = 1;
        for(auto ch : s)
            ans *= primes[(ch - 97)];
        return ans;
    }
};