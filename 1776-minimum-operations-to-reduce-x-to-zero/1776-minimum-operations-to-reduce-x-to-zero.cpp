class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        
        int target = total_sum - x;
        if (target < 0) return -1;
        if (target == 0) return nums.size();
        
        int max_len = -1;
        int current_sum = 0;
        int left = 0;
        int n = nums.size();
        
        for (int right = 0; right < n; ++right) {
            current_sum += nums[right];
            
            while (current_sum > target && left <= right) {
                current_sum -= nums[left];
                left++;
            }
            
            if (current_sum == target) {
                max_len = max(max_len, right - left + 1);
            }
        }
        
        return max_len != -1 ? n - max_len : -1;
    }
};