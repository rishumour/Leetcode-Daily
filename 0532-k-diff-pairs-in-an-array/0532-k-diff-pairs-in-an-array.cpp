class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }
        
        int pairs = 0;
        for (auto& [num, count] : counts) {
            if (k == 0) {
                if (count > 1) {
                    pairs++;
                }
            } else {
                if (counts.count(num + k)) {
                    pairs++;
                }
            }
        }
        
        return pairs;        
    }
};