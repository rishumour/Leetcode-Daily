class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max((long long)nums[0] - nums[1], (long long)nums[1] - nums[0]);
        
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 1) {
                total -= nums[i];
            } else {
                total += nums[i];
            }
        }
        
        long long sum = nums[0] - nums[1];
        long long max_sum = max(total, total - 2LL * sum);
        long long max_even_prefix = nums[0];
        long long max_odd_prefix = max(0LL, sum);
        
        for (int i = 2; i < n; ++i) {
            if (i % 2 == 1) {
                sum -= nums[i];
                max_sum = max(max_sum, total - 2LL * (sum - max_odd_prefix));
                max_odd_prefix = max(max_odd_prefix, sum);
            } else {
                sum += nums[i];
                max_sum = max(max_sum, total - 2LL * (sum - max_even_prefix));
                max_even_prefix = max(max_even_prefix, sum);
            }
        }
        
        return max_sum;
    }
};