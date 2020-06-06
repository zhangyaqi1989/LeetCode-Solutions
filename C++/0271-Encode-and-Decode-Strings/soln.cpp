class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans;
        for(const auto & token : strs) {
            string token_m = regex_replace(token, regex("#"), "##");
            ans += token_m + " # ";
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        string delimiter = " # ";
        vector<string> ans;
        const int kN = s.length();
        for(int i = 0; i < kN; ) {
            int j = s.find(delimiter, i);
            string token = s.substr(i, j - i);
            ans.push_back(regex_replace(token, regex("##"), "#"));
            i = j + 3;
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
