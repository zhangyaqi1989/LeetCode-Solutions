class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        map<int, int> counter;
        map<int, pair<int, int>> indexes;
        int ans = nums.size();
        for (int i = 0; i < nums.size(); ++i)
        {
            counter[nums[i]]++;
            if (!indexes.count(nums[i]))
            {
                indexes[nums[i]] = make_pair(i, i);
            } else
            {
                indexes[nums[i]].second = i;
            }
        }
        int max_fre = 0;
        set<int> fre_nums;
        for(auto it = counter.begin(); it != counter.end(); ++it)
        {
            if(it -> second > max_fre) {
                max_fre = it->second;
            }
        }
        for (auto it = counter.begin(); it != counter.end(); ++it)
        {
            if(it -> second == max_fre)
                fre_nums.insert(it->first);
        }
        for(auto it = indexes.begin(); it != indexes.end(); ++it)
        {
            if(fre_nums.count(it->first) && it->second.second - it->second.first + 1 < ans)
                ans = it->second.second - it->second.first + 1;
        }
        return ans;
    }
};