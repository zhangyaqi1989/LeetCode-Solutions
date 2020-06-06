auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int val;
    TrieNode(int val): val(val){}
};

class MapSum {
    TrieNode * root;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode(0);
    }
    
    void insert(string key, int val) {
        TrieNode * cur = root;
        for(auto ch : key) {
            if(cur->children.find(ch) == cur->children.end()) // if not exist'
                cur->children[ch] = new TrieNode(0);
            cur = cur->children[ch];
        }
        cur->val = val;
    }
    
    int sum(string prefix) {
        TrieNode * cur = root;
        for(auto ch : prefix) {
            if(cur->children.find(ch) == cur->children.end()) return 0;
            cur = cur->children[ch];
        }
        int cnt = 0;
        traverse(cur, cnt);
        return cnt;
    }
    
    void traverse(TrieNode* node, int & cnt) {
        if (node) {
            cnt += node->val;
            for(auto it : node->children) {
                traverse(it.second, cnt);
            }
        }
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
