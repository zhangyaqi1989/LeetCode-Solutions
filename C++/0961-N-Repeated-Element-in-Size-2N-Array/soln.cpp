class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int counter[10000] = {0};
        for(int num : A) {
            if (counter[num]++ == 1)
                return num;
        }
        return -1;
    }
};
