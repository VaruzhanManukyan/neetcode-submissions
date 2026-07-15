class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> set_{};

        for (auto num : nums) {
            if (set_.find(num) != set_.end()) {
                return true;
            }
            set_.insert(num);
        }
        return false;
    }
};