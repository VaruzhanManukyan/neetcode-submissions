class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> set_;
        int left = 0;
        int result = 0;
        for (std::size_t i = 0; i < s.size(); ++i) {
            if (set_.find(s[i]) != set_.end()) {
                while (set_.find(s[i]) != set_.end()) {
                    set_.erase(s[left]);
                    ++left;
                }
            }
            set_.insert(s[i]);
            result = std::max(result, static_cast<int>(set_.size()));
        }

        return result;
    }
};
