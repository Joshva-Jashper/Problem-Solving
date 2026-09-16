class Solution {
public:
    int numberOfSets(int n, int k) {
        long long MOD = 1e9 + 7;
        long long N = n + k - 1;
        long long R = 2 * k;

        if (R > N) return 0;

        long long num = 1, den = 1;
        for (long long i = 1; i <= R; ++i) {
            num = (num * (N - i + 1)) % MOD;
            den = (den * i) % MOD;
        }
        long long den_inv = 1;
        long long base = den;
        long long exp = MOD - 2;
        while (exp > 0) {
            if (exp & 1) den_inv = (den_inv * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }

        return (num * den_inv) % MOD;
    }
};