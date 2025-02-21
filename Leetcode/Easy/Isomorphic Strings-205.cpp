
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> map_s, map_t;

        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i], c2 = t[i];

            // Check if mapping exists in s → t
            if (map_s.count(c1)) {
                if (map_s[c1] != c2) return false;
            } else {
                map_s[c1] = c2;
            }

            // Check if mapping exists in t → s
            if (map_t.count(c2)) {
                if (map_t[c2] != c1) return false;
            } else {
                map_t[c2] = c1;
            }
        }
        return true;
    }
};
