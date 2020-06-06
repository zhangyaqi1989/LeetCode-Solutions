class TrieNode {
public:
    bool is_word;
    int cnt;
    unordered_map<char, TrieNode *> children;

    TrieNode(): is_word(false), cnt(0) {}
    ~TrieNode() {
        for(auto & p : children) {
            if (p.second != nullptr) {
                delete p.second;
                p.second = nullptr;
            }
        }
    }
};

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root_ = TrieNode();
        const int n = times.size();
        for(int i = 0; i < n; ++i) {
            string & s = sentences[i];
            int time = times[i];
            TrieNode * cur = & root_;
            for(char ch : s) {
                auto it = cur->children.find(ch);
                if (it == cur->children.end()) {
                    cur->children[ch] = new TrieNode();
                    cur = cur->children[ch];
                } else {
                    cur = it->second;
                }
            }
            cur->is_word = true;
            cur->cnt += time;
        }
        cur_ = & root_;
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            // cout << typed_ << endl;
            TrieNode * cur = & root_;
            for(char ch : typed_) {
                auto it = cur->children.find(ch);
                if (it == cur->children.end()) {
                    cur->children[ch] = new TrieNode();
                    cur = cur->children[ch];
                } else {
                    cur = it->second;
                }
            }
            cur->is_word = true;
            cur->cnt += 1;
            cur_ = & root_;
            typed_ = "";
            return {};
        } else {
            // update cur_ and return the top 3
            vector<string> ans;
            typed_ += c;
            if (cur_ != nullptr) {
                auto it = cur_->children.find(c);
                if (it == cur_->children.end()) cur_ = nullptr;
                else cur_ = it->second;
                if (cur_ == nullptr) return ans;
                stack<pair<TrieNode *, string>> st;
                st.push({cur_, typed_});
                set<pair<int, string>> cands;
                while (!st.empty()) {
                    auto node = st.top();
                    st.pop();
                    if (node.first->is_word) {
                        cands.insert({-node.first->cnt, node.second});
                    }
                    for(auto & p : node.first->children) {
                        char ch = p.first;
                        TrieNode * child = p.second;
                        st.push({child, node.second + ch});
                    }
                }
                int k = 3;
                auto ptr = cands.begin();
                while (k-- > 0 && ptr != cands.end()) {
                    ans.push_back(ptr->second);
                    ++ptr;
                }
                return ans;
            } else {
                return ans;
            }
        }
    }

private:
    TrieNode root_;
    string typed_;
    TrieNode * cur_;
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
