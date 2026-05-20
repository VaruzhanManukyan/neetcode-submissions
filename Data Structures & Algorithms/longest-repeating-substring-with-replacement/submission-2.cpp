class Solution {
public:
    int characterReplacement(string s, int k) {
        const int size = s.size();
        int max = 0;
        int left = 0;
        int result = 0;
        std::vector<int> count(26, 0);

        for (std::size_t i = 0; i < size; ++i) {
            ++count[s[i] - 'A'];

            max = std::max(max, count[s[i] - 'A']);

            if ((i - left + 1) - max > k) {
                --count[s[left] - 'A'];
                ++left;
            }

            result = std::max(result, static_cast<int>(i - left + 1));
        }    
        return result;    
    }
};
