class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {
        vector<int> ans;
        if(low > high) return ans;
        deque<int> frontier = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        if(low == 0) ans.push_back(0);
        while(!frontier.empty()) {
            int num = frontier.front();
            frontier.pop_front();
            if(low <= num && num <= high) {
                ans.push_back(num);
            }
            if(num <= high / 10) {
                int d = num % 10;
                if (d > 0) frontier.push_back(num * 10 + d - 1);
                if (d < 9) frontier.push_back(num * 10 + d + 1);
            }
        }
        return ans;
    }
};
