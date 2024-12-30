class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign = 1;
        if(dividend==divisor)return 1;
        if (dividend < 0 && divisor > 0) {
            sign = 0;
        }
        if (dividend > 0 && divisor < 0) {
            sign = 0;
        }
        if(dividend<0 && divisor<0){
            sign=1;
        }
       long x = abs((long)dividend);
        long y = abs((long)divisor);
        long ans = 0;
        while (x >= y) {
            int count = 0;
            while (x >= (y << (count + 1))) {
                count=count+1;
            }
            ans = ans + ((long)1 << count);
            x = x - (y << count);
        }

        if (ans >=(1L<<31) && sign) {
            cout<<ans<<"-ve";
            return INT_MAX;
        }
        if (ans >= (1L<<31) && !sign) {
            cout<<ans<<"+ve";
            return INT_MIN;
        }
        if(!sign){
            return -ans;
        }
        else{
            return ans;
        }
    }
};