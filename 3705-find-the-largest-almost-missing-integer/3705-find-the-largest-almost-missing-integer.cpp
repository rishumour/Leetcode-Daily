class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        
        if (k == n) {
            int max_val = nums[0];
            for (int num : nums) {
                max_val = max(max_val, num);
            }
            return max_val;
        }
        
        vector<int> count(51, 0);
        for (int num : nums) {
            count[num]++;
        }
        
        if (k == 1) {
            int ans = -1;
            for (int i = 0; i <= 50; ++i) {
                if (count[i] == 1) {
                    ans = max(ans, i);
                }
            }
            return ans;
        }
        
        int ans = -1;
        if (count[nums[0]] == 1) ans = max(ans, nums[0]);
        if (count[nums[n - 1]] == 1) ans = max(ans, nums[n - 1]);
        
        return ans;
    }
};