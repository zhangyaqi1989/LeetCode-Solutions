/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        // cout << extractHostname(startUrl) << endl;
        string hostname = extractHostname(startUrl);
        stack<string> st;
        st.push(startUrl);
        vector<string> ans;
        unordered_set<string> visited = {startUrl};
        while (!st.empty()) {
            string url = st.top();
            st.pop();
            ans.push_back(url);
            for(string nei : htmlParser.getUrls(url)) {
                if (extractHostname(nei) == hostname && visited.find(nei) == visited.end()) {
                    visited.insert(nei);
                    st.push(nei);
                }
            }
        }
        return ans;
    }
private:
    string extractHostname(string url) {
        int idx = url.find('/', 7);
        return url.substr(0, idx);
    }
};
