class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size();
        int counter[n + 1] = {0};
        int mx = 0, top = 0;
        for(int i = 0; i < n; ++i) {
            int p = persons[i], t = times[i];
            if (++counter[p] >= mx) {
                mx = counter[p];
                top = p;
            }
            leads[t] = top;
        }
    }
    
    int q(int t) {
        auto it = leads.upper_bound(t);
        return prev(it)->second;
        
    }
private:
    map<int, int> leads;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
