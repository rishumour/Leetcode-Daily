class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        int ans = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            int days_needed = 1;
            int current_load = 0;
            
            for (int weight : weights) {
                if (current_load + weight > mid) {
                    days_needed++;
                    current_load = weight;
                } else {
                    current_load += weight;
                }
            }
            
            if (days_needed <= days) {
                ans = mid;
                right = mid - 1; 
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};