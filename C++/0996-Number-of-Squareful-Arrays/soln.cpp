class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        map<int, int> counter;
        for(int num : A) ++counter[num];
        map<int, vector<int>> cands;
        for(auto & p1 : counter) {
            int a = p1.first;
            for(auto & p2 : counter) {
                int b = p2.first;
                if (valid(a, b)) cands[a].push_back(b);
            }
        }
        int cnt = 0, n = A.size();
        for(auto & p1 : counter) {
            helper(p1.first, n - 1, cnt, counter, cands);
        }
        return cnt;
    }
    
    void helper(int cur, int left, int & cnt, map<int, int> & counter, map<int, vector<int>> & cands) {
        if (left == 0) {
            ++cnt;
        } else {
            --counter[cur];
            for(auto cand : cands[cur])
                if(counter[cand] > 0)
                    helper(cand, left - 1, cnt, counter, cands);
            ++counter[cur];
        }
    }

    bool valid(int a, int b) {
        int root = sqrt(a + b);
        return root * root == a + b;
    }
};
