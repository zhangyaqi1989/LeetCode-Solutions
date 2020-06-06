ass ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int hi = 1;
        while (reader.get(hi) < target) hi <<= 1;
        int lo = hi >> 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int r = reader.get(mid);
            if (r == target) return mid;
            else if (r < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }
};
