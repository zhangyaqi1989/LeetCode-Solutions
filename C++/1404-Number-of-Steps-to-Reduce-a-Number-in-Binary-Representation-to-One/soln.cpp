class Solution {
public:
    int numSteps(string s) {
        int cnt = 0;
        deque<char> dq(s.begin(), s.end());
        while(dq.size() != 1 || dq.back() != '1') {
            if(dq.back() == '0') {
                dq.pop_back();
            } else {
                dq.back() = '0';
                int i = dq.size() - 2;
                while(i >= 0 && dq[i] == '1') {
                    dq[i--] = '0';
                }
                if(i < 0) dq.push_front('1');
                else dq[i] = '1';
            }
            ++cnt;
        }
        return cnt;
    }
};
