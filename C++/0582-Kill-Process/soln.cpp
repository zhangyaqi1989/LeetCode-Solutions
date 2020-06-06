class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> tree;
        for (auto i = 0; i < pid.size(); ++i)
            tree[ppid[i]].push_back(pid[i]);
        vector<int> ans;
        stack<int> s;
        s.push(kill);
        while (!s.empty())
        {
            int process = s.top();
            ans.push_back(process);
            s.pop();
            for (auto child : tree[process])
                s.push(child);
        }
        return ans;
    }
};