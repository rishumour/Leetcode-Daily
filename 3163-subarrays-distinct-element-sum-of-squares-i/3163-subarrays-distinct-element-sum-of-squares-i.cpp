class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        
        for (int i = 0; i < n; ++i) {
            vector<bool> seen(101, false);
            int distinct_count = 0;
            
            for (int j = i; j < n; ++j) {
                if (!seen[nums[j]]) {
                    seen[nums[j]] = true;
                    distinct_count++;
                }
                total_sum += distinct_count * distinct_count;
            }
        }
        
        return total_sum;
    }
};