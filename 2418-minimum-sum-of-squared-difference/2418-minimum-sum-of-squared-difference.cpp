class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        vector<int> counts(100001, 0);
        
        for (int i = 0; i < n; ++i) {
            int diff = abs(nums1[i] - nums2[i]);
            counts[diff]++;
        }
        
        for (int d = 100000; d > 0 && k > 0; --d) {
            if (counts[d] > 0) {
                long long take = min(k, (long long)counts[d]);
                counts[d] -= take;
                counts[d - 1] += take;
                k -= take;
            }
        }
        
        long long ans = 0;
        for (long long d = 1; d <= 100000; ++d) {
            if (counts[d] > 0) {
                ans += counts[d] * d * d;
            }
        }
        
        return ans;
    }
};