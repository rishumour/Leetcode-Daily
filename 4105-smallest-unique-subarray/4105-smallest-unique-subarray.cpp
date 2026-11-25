class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        const long long MOD1 = 1000000007;
        const long long MOD2 = 1000000009;
        const long long BASE1 = 131313;
        const long long BASE2 = 137371;

        vector<long long> p1(n + 1, 1), p2(n + 1, 1);
        vector<long long> h1(n + 1, 0), h2(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            p1[i + 1] = (p1[i] * BASE1) % MOD1;
            p2[i + 1] = (p2[i] * BASE2) % MOD2;
            h1[i + 1] = (h1[i] * BASE1 + nums[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE2 + nums[i]) % MOD2;
        }

        auto check = [&](int len) -> bool {
            unordered_map<uint64_t, int> freq;
            freq.reserve(n - len + 1);
            for (int i = 0; i + len <= n; ++i) {
                long long x1 = (h1[i + len] - h1[i] * p1[len] % MOD1 + MOD1) % MOD1;
                long long x2 = (h2[i + len] - h2[i] * p2[len] % MOD2 + MOD2) % MOD2;
                uint64_t key = (static_cast<uint64_t>(x1) << 32) | static_cast<uint64_t>(x2);
                freq[key]++;
            }
            for (const auto& [k, v] : freq) {
                if (v == 1) return true;
            }
            return false;
        };

        int lo = 1, hi = n, ans = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};