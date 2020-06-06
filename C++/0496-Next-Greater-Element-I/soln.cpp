class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        unordered_map<int, int> m;
        for(auto num : nums) {
            while (!s.empty() && num > s.top()) {
                m[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        vector<int> ans(findNums.size(), -1);
        for(int i = 0; i < findNums.size(); ++i) {
            if(m.count(findNums[i])) ans[i] = m[findNums[i]];
        }
        return ans;
    }
};