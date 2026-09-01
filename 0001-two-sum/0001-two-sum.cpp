class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> res;
        for (int i = 0; i < n; ++i) {
            res.push_back({nums[i], i});
        }
        
        sort(res.begin(), res.end());
        
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int sum = res[left].first + res[right].first;
            
            if (sum == target) {
                return {res[left].second, res[right].second};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        
        return {};
    }
};

// first sort the array and then solve the pair sum