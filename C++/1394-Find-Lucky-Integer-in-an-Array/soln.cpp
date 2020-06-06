class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> counter;
        for(int num : arr) ++counter[num];
        for(auto it = counter.rbegin(); it != counter.rend(); ++it) {
            if (it->first == it->second) return it->first;
        }
        return -1;
    }
};
