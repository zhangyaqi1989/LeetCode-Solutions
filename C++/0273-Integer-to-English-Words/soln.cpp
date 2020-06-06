vector<string> lessthan20  = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
vector<string> tens = {"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
vector<string> thousands = {"","Thousand","Million","Billion"};
class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string ans;
        for(int i = 0; i < 4; ++i) {
            if (num % 1000 != 0) {
                ans = helper(num % 1000) + thousands[i] + " " + ans;
            }
            num /= 1000;
        }
        
        const int n = ans.length();
        int lo = 0, hi = n - 1;
        while (lo < n && ans[lo] == ' ') ++lo;
        while (hi >= 0 && ans[hi] == ' ') --hi;
        return ans.substr(lo, hi - lo + 1);
    }
    
private:
    string helper(int num) {
        if (num == 0) return "";
        else if (num < 20) return lessthan20[num] + " ";
        else if (num < 100) return tens[num / 10] + " " + helper(num % 10);
        else return lessthan20[num / 100] + " Hundred " + helper(num % 100);
    } 
};
