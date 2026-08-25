class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> present_nums(nums.begin(), nums.end());
        for (int i = 1; ; ++i) {
            int current_multiple = k * i;
            if (present_nums.find(current_multiple) == present_nums.end()) {
                return current_multiple;
            }
        }
    }
};