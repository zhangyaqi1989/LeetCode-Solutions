class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int cnt = 0;
        const int kN = startTime.size();
        for(int i = 0; i < kN; ++i) cnt += (queryTime >= startTime[i] && queryTime <= endTime[i]);
        return cnt;
    }
};
