class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal; // xoring  create a fliping bit 1
        int cnt =0;
        while(x){
            cnt += x&1; // 1 = 0001 , so and with 1 will count the flips
            x>>=1;      // left shift for next bit
        }
        return cnt;
    }
};
