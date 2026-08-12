class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charIndex(128, -1);
        int maxLen = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            if (charIndex[s[right]] >= left) {
                left = charIndex[s[right]] + 1;
            }
            charIndex[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};