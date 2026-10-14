class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        if (n < 2) return {};
        
        vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        
        for (int p = 2; p * p <= n; ++p) {
            if (is_prime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    is_prime[i] = false;
                }
            }
        }
        
        vector<int> ans;
        long long current_sum = 0;
        
        for (int p = 2; p <= n; ++p) {
            if (is_prime[p]) {
                if (current_sum + p <= s) {
                    current_sum += p;
                    ans.push_back(p);
                } else {
                    break;
                }
            }
        }
        
        return ans;
    }
};