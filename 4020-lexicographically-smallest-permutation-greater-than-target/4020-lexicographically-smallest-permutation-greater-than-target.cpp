class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;
        
        int best_i = -1;
        for (int i = 0; i < s.length(); ++i) {
            bool can_diverge = false;
            for (int c = target[i] - 'a' + 1; c < 26; ++c) {
                if (count[c] > 0) {
                    can_diverge = true;
                    break;
                }
            }
            if (can_diverge) {
                best_i = i;
            }
            
            if (count[target[i] - 'a'] > 0) {
                count[target[i] - 'a']--;
            } else {
                break;
            }
        }
        
        if (best_i == -1) return "";
        
        vector<int> rem(26, 0);
        for (char c : s) rem[c - 'a']++;
        
        string ans = "";
        for (int i = 0; i < best_i; ++i) {
            ans += target[i];
            rem[target[i] - 'a']--;
        }
        
        for (int c = target[best_i] - 'a' + 1; c < 26; ++c) {
            if (rem[c] > 0) {
                ans += (char)(c + 'a');
                rem[c]--;
                break;
            }
        }
        
        for (int c = 0; c < 26; ++c) {
            while (rem[c] > 0) {
                ans += (char)(c + 'a');
                rem[c]--;
            }
        }
        
        return ans;
    }
};