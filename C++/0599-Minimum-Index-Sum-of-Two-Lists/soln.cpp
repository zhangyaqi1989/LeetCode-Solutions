static const auto ___=[](){ ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> m1;
        map<string, int> m2;
        for(auto i = 0; i < list1.size(); ++i)
            m1[list1[i]] = i;
        for(auto i = 0; i < list2.size(); ++i)
            m2[list2[i]] = i;
        if (m2.size() > m1.size())
            swap(m1, m2);
        priority_queue<pair<int, string>> pq;
        vector<string> ans;
        for(auto it = m1.begin(); it != m1.end(); ++it)
        {
            if(m2.find(it->first) != m2.end())
                pq.push(make_pair(- m1[it->first] - m2[it->first], it->first));
        }
        int min_index_sum = pq.top().first;
        while (pq.size())
        {
            if(pq.top().first == min_index_sum)
            {
                ans.push_back(pq.top().second);
                pq.pop();
            }
            else
                break;
        }
        return ans;
    }
};