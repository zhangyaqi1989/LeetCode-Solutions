class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i = 1; i <= n; ++i) {
            ans.push_back(encode(i));
        }
        return ans;
    }
    
    string encode(int n) {
        if (n % 15 == 0) return "FizzBuzz";
        else if (n % 3 == 0) return "Fizz";
        else if (n % 5 == 0) return "Buzz";
        else return to_string(n);
    }
};