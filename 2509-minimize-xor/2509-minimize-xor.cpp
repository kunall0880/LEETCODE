class Solution {
public:
    bool isSet(int& x, int n) { return x & (1 << n); }
    bool setBit(int& x, int n) { return x = x | (1 << n); }
    int minimizeXor(int num1, int num2) {
        int x = 0;

        int reqset = __builtin_popcount(num2);
        for(int i=32-1;i>=0&&reqset>0;i--){
            if(isSet(num1,i)){
                setBit(x,i);
                reqset--;
            }
        }
        if(reqset<=0){
            return x;
        }
        for(int i=0;i<32 && reqset>0;i++){
            if(!isSet(num1,i)){
                setBit(x,i);
                reqset--;
            }
        }

        return x;
    }
};