class Solution {
public:
    bool isPalindrome(string s) {
        std::size_t start = 0;
        std::size_t end = s.size() - 1;
        while (end > start) {
            if (!std::isalnum(s[start])) {
                ++start;
                continue;
            }
            if (!std::isalnum(s[end])) {
                --end;
                continue;
            }

            if (std::tolower(s[start]) != tolower(s[end])) {
                return false;
            }

            ++start;
            --end;
        }

        return true;
    }
};
