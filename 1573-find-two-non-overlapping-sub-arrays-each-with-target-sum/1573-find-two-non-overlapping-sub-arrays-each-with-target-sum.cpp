class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n, INT_MAX);
        int ans = INT_MAX;
        
        int left = 0, right = 0, current_sum = 0;
        int best_so_far = INT_MAX;
        
        while (right < n) {
            current_sum += arr[right];
            
            while (current_sum > target && left <= right) {
                current_sum -= arr[left];
                left++;
            }
            
            if (current_sum == target) {
                int len = right - left + 1;
                if (left > 0 && min_len[left - 1] != INT_MAX) {
                    ans = min(ans, len + min_len[left - 1]);
                }
                best_so_far = min(best_so_far, len);
            }
            
            min_len[right] = best_so_far;
            right++;
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};