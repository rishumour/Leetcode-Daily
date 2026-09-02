class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightMax(n);
        
        rightMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i + 1], nums[i]);
        }
        
        int left = 0;
        int right = 0;
        int maxWidth = 0;

        while (right < n) {
            if (nums[left] <= rightMax[right]) {
                maxWidth = max(maxWidth, right - left);
                right++;
            } else {
                left++;
            }
        }
        
        return maxWidth;
    }
};