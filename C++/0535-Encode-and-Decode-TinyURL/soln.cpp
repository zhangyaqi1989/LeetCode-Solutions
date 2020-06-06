class Solution {
public:
    map<int, string> urls;
    int size = 0;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        urls[size] = longUrl;
        return "http://tinyurl.com/" + to_string(size++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int idx = 0, unit = 1, n = shortUrl.length();
        for(int i = n - 1; i >= 0; --i) {
            if (isdigit(shortUrl[i])) {
                idx += unit * (shortUrl[i] - '0');
            } else {
                break;
            }
        }
        return urls[idx];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
