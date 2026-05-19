class Solution {
public:
    int maxArea(vector<int>& heights) {
        int result = 0;
        int start = 0;
        int end = heights.size() - 1;

        while (start < end) {
            if (heights[start] < heights[end]) {
                result = std::max(heights[start] * (end - start), result);
                ++start;
            } else {
                result = std::max(heights[end] * (end - start), result);
                --end;
            }
        }

        return result;
    }
};
