class Solution {
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        unordered_map<string, vector<string>> graph;
        for(const auto & p : synonyms) {
            string u = p[0], v = p[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<string> tokens;
        const int kN = text.length();
        int lo = 0, hi = 0;
        while (lo < kN) {
            int hi = text.find(' ', lo);
            if (hi == string::npos) hi = kN;
            tokens.push_back(text.substr(lo, hi - lo));
            lo = hi + 1;
        }
        vector<string> ans;
        vector<string> words;
        Dfs(0, tokens, graph, & words, & ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
    
private:
    string Combine(const vector<string> & words) {
        string ans;
        const int kN = words.size();
        for(int i = 0; i < kN; ++i) {
            if (i > 0) ans += " ";
            ans += words[i];
        }
        return ans;
    }
    
    void Dfs(int idx, const vector<string> & tokens, const unordered_map<string, vector<string>> & graph,
             vector<string> * words, vector<string> * ans) {
        if (idx == tokens.size()) {
            ans->push_back(Combine(*words));
        } else {
            string next_word = tokens[idx];
            vector<string> synonyms;
            GetAllSynonyms(graph, next_word, & synonyms);
            for(string item : synonyms) {
                words->push_back(item);
                Dfs(idx + 1, tokens, graph, words, ans);
                words->pop_back();
            }
        }
    }
    
    void GetAllSynonyms(const unordered_map<string, vector<string>> & graph, const string & start, vector<string> * synonyms) {
        stack<string> st;
        st.push(start);
        unordered_set<string> visited = {start};
        while (!st.empty()) {
            string u = st.top();
            st.pop();
            synonyms->push_back(u);
            auto it = graph.find(u);
            if (it == graph.end()) continue;
            for(string v : it->second) {
                if (visited.find(v) == visited.end()) {
                    visited.insert(v);
                    st.push(v);
                }
            }
        }
    }
};
