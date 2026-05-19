class Solution {
public:
    int maxArea(vector<int>& heights) {
        int result = 0;
        int start = 0;
        int end = heights.size() - 1;

        while (start < end) {
            int width = end - start;
            
            if (heights[start] < heights[end]) {
                result = std::max(heights[start] * width, result);
                ++start;
            } else {
                result = std::max(heights[end] * width, result);
                --end;
            }
        }

        return result;
    }
};
