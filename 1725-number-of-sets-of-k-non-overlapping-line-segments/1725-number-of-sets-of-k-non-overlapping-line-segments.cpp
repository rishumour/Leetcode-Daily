class Solution {
long long power(long long base, long long exp) {
        long long res = 1;
        long long MOD = 1e9 + 7;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, 1e9 + 7 - 2);
    }

public:
    int numberOfSets(int n, int k) {
        long long MOD = 1e9 + 7;
        int N = n + k - 1;
        int K = 2 * k;
        
        if (K > N) return 0;
        
        long long num = 1;
        long long den = 1;
        
        for (int i = 0; i < K; ++i) {
            num = (num * (N - i)) % MOD;
            den = (den * (i + 1)) % MOD;
        }
        
        return (num * modInverse(den)) % MOD;
    }
};