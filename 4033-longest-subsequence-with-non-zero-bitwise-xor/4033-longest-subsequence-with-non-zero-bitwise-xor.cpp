class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total_xor = 0;
        bool has_nonzero = false;
        
        for (int num : nums) {
            total_xor ^= num;
            if (num != 0) {
                has_nonzero = true;
            }
        }
        
        if (total_xor != 0) {
            return nums.size();
        } else if (has_nonzero) {
            return nums.size() - 1;
        } else {
            return 0;
        }
    }
};