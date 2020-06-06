// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int lo = 0, hi = 200000;
        int INF = (1 << 31) - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int v = reader.get(mid);
            if (v == INF) {
                hi = mid - 1;
            } else {
                if (v < target) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }
        }
        return reader.get(lo) == target ? lo : -1;
    }
};
