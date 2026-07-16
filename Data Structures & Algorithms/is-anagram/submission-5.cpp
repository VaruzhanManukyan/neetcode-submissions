class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        std::unordered_map<short, short> map_{};
        for (auto& c : s) {
            map_[c]++;
        }

        for (auto& c : t) {
            map_[c]--;
        }

        for (auto& [key, value] : map_) {
            if (value != 0) {
                return false;
            }
        }

        return true;
    }
};
