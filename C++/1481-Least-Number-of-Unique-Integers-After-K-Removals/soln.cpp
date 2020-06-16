class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> counter;
        for(int num : arr) ++counter[num];
        vector<int> cnts;
        for(const auto & p : counter) cnts.push_back(p.second);
        sort(cnts.begin(), cnts.end());
        int ans = counter.size();
        for(int cnt : cnts) {
            if(k >= cnt) {
                k -= cnt;
                --ans;
            } else break;
        }
        return ans;
    }
};
