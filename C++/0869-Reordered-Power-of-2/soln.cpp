class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string N_str = to_string(N);
        int digits[10] = {0};
        for(char ch : N_str) {
            ++digits[ch - '0'];
        }
        for(int i = 0; i < 31; ++i) {
            int num = (1 << i);
            // cout << num << " " << i << endl;
            string str = to_string(num);
            int temp[10] = {0};
            for(char ch : str) {
                ++temp[ch - '0'];
            }
            bool valid = true;
            for(int j = 0; j < 10; ++j) {
                if (temp[j] != digits[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) return true;
        }
        return false;
    }
    
};
