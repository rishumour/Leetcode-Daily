class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool hasEven = false;
        bool hasOdd = false;
        int minVal = INT_MAX;
        
        for (int num : nums1) {
            if (num % 2 == 0) hasEven = true;
            else hasOdd = true;
            
            minVal = min(minVal, num);
        }
        if (!hasEven || !hasOdd) return true;
        return minVal % 2 != 0;
    }
};