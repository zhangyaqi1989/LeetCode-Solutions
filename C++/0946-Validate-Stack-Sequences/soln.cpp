class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0;
        for (int item : pushed) {
            s.push(item);
            while (s.size() && s.top() == popped[i]) {
                ++i;
                s.pop();
            }
        }
        return i == popped.size();
    }
};