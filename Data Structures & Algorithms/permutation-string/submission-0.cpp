class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        std::vector<int> substring(26, 0);
        std::vector<int> window(26, 0);

        for (std::size_t i = 0; i < s1.size(); ++i) {
            ++substring[s1[i] - 'a'];
            ++window[s2[i] - 'a'];
        }

        if (substring == window) {
            return true;
        }

        for (std::size_t i = s1.size(); i < s2.size(); ++i) {
            --window[s2[i - s1.size()] - 'a'];
            ++window[s2[i] - 'a'];

            if (window == substring) {
                return true;
            }
        }
        return false;
    }
};
