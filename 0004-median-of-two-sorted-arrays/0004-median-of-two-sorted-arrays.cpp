class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int totalSize = n + m; 

        int midVal = totalSize / 2;
        int target;
        if(totalSize % 2 == 0){
            target = midVal - 1;
        }else{
            target = midVal;
        }

        int val1 = 0, val2 = 0;
        int i = 0, j = 0, steps = 0;

        while (steps <= midVal){
            int currValue;
            if (i < n && (j == m || nums1[i] < nums2[j])) {
                currValue = nums1[i];
                i++;
            } else {
                currValue = nums2[j];
                j++;
            }
            if (steps == target) {
                val1 = currValue;
            }
            if (steps == midVal) {
                val2 = currValue;
            }
            steps++;
        }
        return (val1 + val2) / 2.0;
    }
};