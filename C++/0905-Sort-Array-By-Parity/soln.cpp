typedef vector<int> vi;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vi evens, odds;
        for(int item : A) {
            if (item % 2) odds.push_back(item);
            else evens.push_back(item);
        }
        evens.insert(end(evens), begin(odds), end(odds));
        return evens;
    }
};