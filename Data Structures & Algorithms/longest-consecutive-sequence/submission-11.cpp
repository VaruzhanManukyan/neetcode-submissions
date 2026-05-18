class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> set_(nums.begin(), nums.end());
        int longest = 0;

        for (const int& num : nums) {
            if (set_.find(num - 1) == set_.end()) {
                int length = 1;
                int current = num;

                while(set_.find(current + 1) != set_.end()) {
                    ++length;
                    ++current;
                }

                if (length > longest) {
                    longest = length;
                }
            }
        }

        return longest;
    }
};
