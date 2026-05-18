class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> set_(nums.begin(), nums.end());

        int longest = 0;

        for (const int num : set_) {

            if (set_.find(num - 1) == set_.end()) {

                int current = num;
                int length = 1;

                while (set_.find(current + 1) != set_.end()) {
                    ++current;
                    ++length;
                }

                longest = std::max(longest, length);
            }
        }

        return longest;
    }
};