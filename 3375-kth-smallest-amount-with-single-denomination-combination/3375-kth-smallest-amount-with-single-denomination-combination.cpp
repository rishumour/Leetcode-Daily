class Solution {
    long long lcm(long long a, long long b) {
        return (a / std::gcd(a, b)) * b;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        vector<long long> lcms(1 << n, 1);
        for (int mask = 1; mask < (1 << n); ++mask) {
            int lsb = mask & -mask; 
            int bit_idx = __builtin_ctz(lsb);
            lcms[mask] = lcm(lcms[mask ^ lsb], coins[bit_idx]);
        }
        
        long long left = 1;
        long long right = 1LL * k * *min_element(coins.begin(), coins.end());
        long long ans = right;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long count = 0;
            
            for (int mask = 1; mask < (1 << n); ++mask) {
                long long current_lcm = lcms[mask];
                
                if (current_lcm > mid) continue;
                if (__builtin_popcount(mask) % 2 == 1) {
                    count += mid / current_lcm;
                } else {
                    count -= mid / current_lcm;
                }
            }
            if (count >= k) {
                ans = mid;
                right = mid - 1; 
            } else {
                left = mid + 1;  
            }
        }
        
        return ans;
    }
};