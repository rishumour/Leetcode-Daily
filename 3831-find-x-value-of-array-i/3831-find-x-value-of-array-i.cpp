class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);
        
        for (int num : nums) {
            vector<long long> newDp(k, 0);
            int numMod = num % k;
            
            newDp[numMod] = 1;
            
            for (int i = 0; i < k; ++i) {
                if (dp[i] > 0) {
                    int newMod = (1LL * i * numMod) % k;
                    newDp[newMod] += dp[i];
                }
            }
            
            for (int i = 0; i < k; ++i) {
                ans[i] += newDp[i];
                dp[i] = newDp[i];
            }
        }
        
        return ans;
    }
};