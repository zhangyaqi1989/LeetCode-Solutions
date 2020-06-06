class TopVotedCandidate {
private:
    vector<int> times;
    vector<int> leaders;
public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        int leader = persons[0];
        unordered_map<int, int> m;
        for(int i = 0; i < times.size(); ++i)
        {
            m[persons[i]] ++;
            if (m[persons[i]] >= m[leader]) leader = persons[i];
            leaders.push_back(leader);
        }
        this->times = times;
    }
    
    int q(int t) {
        return leaders[upper_bound(times.begin(), times.end(), t) - times.begin() - 1];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */