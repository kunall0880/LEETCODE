class Solution {
public:
    long long MOD = 1000000007;
    long long find_pow(long long a, long long b) {
        if (b <= 0) {
            return 1;
        }
        long long half = find_pow(a, b / 2) % MOD;
        long long res = (half % MOD) * (half % MOD);
        if (b % 2 == 1) {
            res = res * a;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long ft = n / 2;
        long long st = ft, ans = 1;
        if (n % 2 == 1) {
            st = ft + 1;
        }
        ans = (find_pow(5, st) % MOD) * (find_pow(4, ft) % MOD);
        return ans % MOD;
    }
};