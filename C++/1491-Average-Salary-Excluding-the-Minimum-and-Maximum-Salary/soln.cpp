class Solution {
public:
    double average(vector<int>& salary) {
        auto [mn_it, mx_it] = minmax_element(salary.begin(), salary.end());
        const int kN = salary.size();
        return (accumulate(salary.begin(), salary.end(), 0.0) - *mn_it - *mx_it) / (kN - 2);
    }
};
