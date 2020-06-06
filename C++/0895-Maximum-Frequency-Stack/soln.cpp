class FreqStack {
public:
    FreqStack(): mx(0) {
        
    }
    
    void push(int x) {
        auto it = freqs.find(x);
        int x_freq = (it == freqs.end() ? 1 : it->second + 1);
        freqs[x] = x_freq;
        if (x_freq > mx) {
            mx = x_freq;
        }
        if (x_freq + 1 > st.size()) st.resize(x_freq + 1);
        st[x_freq].push_back(x);
    }
    
    int pop() {
        assert(!st[mx].empty());
        int t = st[mx].back();
        --freqs[t];
        st[mx].pop_back();
        if (st[mx].empty()) {
            --mx;
        }
        return t;
    }
    
private:
    vector<vector<int>> st;
    unordered_map<int, int> freqs;
    int mx;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
