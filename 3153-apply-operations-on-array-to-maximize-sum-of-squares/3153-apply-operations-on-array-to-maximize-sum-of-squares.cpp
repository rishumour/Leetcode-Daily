class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bitCount(32, 0);
        
        for (int num : nums) {
            for (int i = 0; i < 32; ++i) {
                if ((num & (1 << i)) != 0) {
                    bitCount[i]++;
                }
            }
        }
        
        long long ans = 0;
        const int MOD = 1e9 + 7;
        
        for (int i = 0; i < k; ++i) {
            long long val = 0;
            for (int j = 0; j < 32; ++j) {
                if (bitCount[j] > 0) {
                    val |= (1 << j);
                    bitCount[j]--;
                }
            }
            ans = (ans + (val * val) % MOD) % MOD;
        }
        
        return ans;
    }
};