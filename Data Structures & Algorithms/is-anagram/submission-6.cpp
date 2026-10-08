class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        std::unordered_map<char, int> map_;

        for (auto& c : s) {
            ++map_[c];
        }

        for(auto& c : t) {
            --map_[c];

            if (map_[c] < 0) {
                return false;
            }
        }

        return true;
    }
};
