class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        if (n == 0) return "";

        vector<int> counts(26, 0);
        for (char c : s) {
            counts[c - 'a']++;
        }

        int odd_count = 0;
        char mid_char = 0;
        vector<int> half_counts(26, 0);

        for (int i = 0; i < 26; ++i) {
            if (counts[i] % 2 != 0) {
                odd_count++;
                mid_char = 'a' + i;
            }
            half_counts[i] = counts[i] / 2;
        }

        if (odd_count > 1) {
            return "";
        }

        int m = n / 2;
        string target_L = target.substr(0, m);
        
        bool can_form_target_L = true;
        vector<int> target_L_counts(26, 0);
        for (char c : target_L) {
            target_L_counts[c - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            if (target_L_counts[i] != half_counts[i]) {
                can_form_target_L = false;
                break;
            }
        }

        if (can_form_target_L) {
            string P_candidate = target_L;
            if (n % 2 != 0) P_candidate += mid_char;
            string rev = target_L;
            reverse(rev.begin(), rev.end());
            P_candidate += rev;

            if (P_candidate > target) {
                return P_candidate;
            }
        }

        for (int len = m - 1; len >= 0; --len) {
            string prefix = target_L.substr(0, len);
            vector<int> prefix_counts(26, 0);
            for (char c : prefix) {
                prefix_counts[c - 'a']++;
            }

            bool valid_prefix = true;
            vector<int> rem_counts(26, 0);
            for (int i = 0; i < 26; ++i) {
                if (prefix_counts[i] > half_counts[i]) {
                    valid_prefix = false;
                    break;
                }
                rem_counts[i] = half_counts[i] - prefix_counts[i];
            }

            if (!valid_prefix) continue;

            char target_c = target_L[len];
            int nxt_c_idx = -1;
            for (int i = target_c - 'a' + 1; i < 26; ++i) {
                if (rem_counts[i] > 0) {
                    nxt_c_idx = i;
                    break;
                }
            }

            if (nxt_c_idx != -1) {
                string L = prefix;
                L += (char)('a' + nxt_c_idx);
                rem_counts[nxt_c_idx]--;

                for (int i = 0; i < 26; ++i) {
                    while (rem_counts[i] > 0) {
                        L += (char)('a' + i);
                        rem_counts[i]--;
                    }
                }

                string P = L;
                if (n % 2 != 0) P += mid_char;
                string rev = L;
                reverse(rev.begin(), rev.end());
                P += rev;

                return P;
            }
        }

        return "";
    }
};