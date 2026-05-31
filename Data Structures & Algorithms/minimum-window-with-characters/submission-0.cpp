class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) {
            return "";
        }

        if (t.empty()) {
            return std::move(s);
        }

        std::unordered_map<char, int> need;
        for (const char& c : t) {
            ++need[c];
        }

        std::unordered_map<char, int> window;
        std::size_t required = need.size();
        std::size_t formed = 0;

        std::size_t left = 0;
        std::size_t best_length = std::numeric_limits<std::size_t>::max();
        std::size_t best_left = 0;

        for (std::size_t i = 0; i < s.size(); ++i) {
            char c = s[i];
            ++window[c];

            if (need.count(c) && window[c] == need[c]) {
                ++formed;
            }

            while (formed == required) {
                std::size_t length = i - left + 1;
                if (length < best_length) {
                    best_length = length;
                    best_left = left;
                }

                char left_char = s[left];
                --window[left_char];
                if (need.count(left_char) && window[left_char] < need[left_char]) {
                    --formed;
                }
                ++left;
            }
        }
        return best_length ==
            std::numeric_limits<std::size_t>::max()
            ? ""
            : s.substr(best_left, best_length);
    }
};