class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int, int> counter;
        for(int num : arr) ++counter[num];
        for(const auto & p : counter) {
            if((p.first == 0 && p.second > 1) || (p.first != 0 && counter.find(2 * p.first) != counter.end())) return true;
        }
        return false;
    }
};
