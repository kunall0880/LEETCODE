class Solution {
public:
    bool isSet(int& x, int n) { return x & (1 << n); }
    bool setBit(int& x, int n) { return x = x | (1 << n); }
    bool unsetBit(int& x, int n) { return x = x & (~(1 << n)); }
    int minimizeXor(int num1, int num2) {
        int x = num1;

        int reqset = __builtin_popcount(num2);
        int currset = __builtin_popcount(x);
        int bit = 0;
        if (reqset > currset) {
            while (currset < reqset) {
                if (!isSet(x, bit)) {
                    setBit(x, bit);
                    currset++;
                }
                bit++;
            }
        } else if (reqset < currset) {
            while (reqset < currset) {
                if (isSet(x, bit)) {
                    unsetBit(x, bit);
                    currset--;
                }
                bit++;
            }
        }
        return x;
    }
};