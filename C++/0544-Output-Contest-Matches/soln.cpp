class Solution {
public:
    string findContestMatch(int n) {
        vector<string> contest;
        for(int i = 1; i <= n; ++i) {
            contest.push_back(to_string(i));
        }
        while(contest.size() > 1) {
            vector<string> temp;
            int m = contest.size();
            int half = m / 2;
            for(int i = 0; i < half; ++i) {
                temp.push_back("(" + contest[i] + "," + contest[m - 1 - i] + ")");
            }
            swap(contest, temp);
        }
        return contest[0];
    }
};
