class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int ncalories = 0;
        int npoints = 0;
        for(size_t i = 0; i < calories.size(); ++i) {
            ncalories += calories[i];
            if (i >= k) ncalories -= calories[i - k];
            if (i >= k - 1) {
                if(ncalories < lower) --npoints;
                else if(ncalories > upper) ++npoints;
            }
        }
        return npoints;
    }
};
