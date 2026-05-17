class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.empty()) {
            return true;
        }

        if (s.size() != t.size()) {
            return false;
        }

        std::unordered_map<char, int> map1;
        std::unordered_map<char, int> map2;

        for (std::size_t i = 0; i < s.size(); ++i) {
                map1[s[i]]++;
                map2[t[i]]++;
        }

        for(const auto& it : map1) {
            if (map2[it.first] != it.second) {
                return false; 
            }
        }
        return true;
    }
};
