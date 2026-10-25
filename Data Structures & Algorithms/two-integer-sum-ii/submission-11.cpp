class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int front = 0;
        int end = numbers.size() - 1;
        
        while (front != end) {
            if (numbers[front] + numbers[end] < target) {
                ++front;
            } else if (numbers[front] + numbers[end] > target) {
                --end;
            } else {
                return {front + 1, end + 1};
            }
        }
        return {};
    }
};
