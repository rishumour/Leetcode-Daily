class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        
        int pos = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                pos = i;
                break;
            }
        }
        
        bool is_forward = true;
        for (int i = 1; i < n; ++i) {
            if (nums[(pos + i) % n] != i) {
                is_forward = false;
                break;
            }
        }
        
        bool is_backward = true;
        for (int i = 1; i < n; ++i) {
            if (nums[(pos + i) % n] != n - i) {
                is_backward = false;
                break;
            }
        }
        
        int ans = 2e9; // Infinity
        
        if (is_forward) {
            ans = min(ans, pos);
            ans = min(ans, n - pos + 2);
        }
        
        if (is_backward) {
            int D = (pos + 1) % n;
            ans = min(ans, D + 1);
            ans = min(ans, n - D + 1);
        }
        
        return ans == 2e9 ? -1 : ans;
    }
};