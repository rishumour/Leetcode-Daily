class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                temp.push_back(i);
            }
        }
        return temp;
    }
};