class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        const int kN = bits.size();
        int last = 1;
        for(int i = 0; i < kN;) {
            if(bits[i] == 0){
                i += 1;
                last = 1;
            } else {
                i += 2;
                last = 2;
            }
        }
        return last == 1;
    }
};
