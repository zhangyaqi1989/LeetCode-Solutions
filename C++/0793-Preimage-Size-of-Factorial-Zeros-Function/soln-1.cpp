typedef long long ll;
class Solution {
public:
    int preimageSizeFZF(int K) {
        ll lo = SmallestValid(K);
        if (NumberOfZeros(lo) != K) return 0;
        ll hi = SmallestValid(K + 1);
        return hi - lo;
    }
    
private:
    ll SmallestValid(int k) {
        ll lo = 0, hi = LLONG_MAX;
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            ll cnt = NumberOfZeros(mid);
            if (cnt < k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
    
    ll NumberOfZeros(ll num) {
        ll cnt = 0;
        while (num >= 5) {
            cnt += num / 5;
            num /= 5;
        }
        return cnt;
    }
};
