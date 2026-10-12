class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int max_len = 0;
        
        vector<int> remainder_map(k, -2);
        vector<int> version(k, -2);
        
        for (int skip = -1; skip < n; ++skip) {
            if (skip != -1) {
                nums[skip] = -nums[skip];
            }
            
            int curr_sum = 0;
            remainder_map[0] = -1;
            version[0] = skip;
            
            for (int i = 0; i < n; ++i) {
                curr_sum = (curr_sum + nums[i]) % k;
                if (curr_sum < 0) {
                    curr_sum += k;
                }
                
                if (version[curr_sum] == skip) {
                    max_len = max(max_len, i - remainder_map[curr_sum]);
                } else {
                    remainder_map[curr_sum] = i;
                    version[curr_sum] = skip;
                }
            }
            
            if (skip != -1) {
                nums[skip] = -nums[skip];
            }
        }
        
        return max_len;
    }
};