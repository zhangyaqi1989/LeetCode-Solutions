auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class RLEIterator {
public:
    vector<int> array;
    int idx;
    
    RLEIterator(vector<int> A) {
        array = A;
        idx = 0;
    }
    
    int next(int n) {
        while (n) {
            if (idx >= array.size()) return -1;
            if(array[idx] < n) {
                n -= array[idx];
                idx += 2;
            } else {
                array[idx] -= n;
                return array[idx + 1];
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
