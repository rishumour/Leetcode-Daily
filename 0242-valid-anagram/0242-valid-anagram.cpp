class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> counts(26, 0);
        
        for (char c : t) {
            counts[c - 'a']++;
        }
        
        for (char c : s) {
            if (--counts[c - 'a'] < 0) {
                return false;
            }
        }
        
        return true;
    }
};