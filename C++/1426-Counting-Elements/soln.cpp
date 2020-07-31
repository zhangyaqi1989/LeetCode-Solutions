class Solution {
public:
    int countElements(vector<int>& arr) {
        map<int, int> counter;
        for(int num : arr) ++counter[num];
        int cnt = 0;
        for(auto it = counter.begin(); it != counter.end(); ++it) {
            if(it != counter.end() && it->first + 1 == next(it)->first) cnt += it->second;
        }
        return cnt;
    }
};
