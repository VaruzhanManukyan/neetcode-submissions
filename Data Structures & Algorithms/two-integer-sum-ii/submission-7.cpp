class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size() - 1;

        while (end > start) {
            int sum = numbers[start] + numbers[end];
            if (target < sum) {
                --end;
            } else if (target > sum) {
                ++start;
            } else {
                return {start + 1, end + 1};
            }
        }
        return {};
    }
};
