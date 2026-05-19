class Solution {
public:
    int maxArea(vector<int>& heights) {
        int result = 0;
        int start = 0;
        int end = heights.size() - 1;

        while (start < end) {
            int width = end - start;

            int height = std::min(heights[start], heights[end]);

            result = std::max(height * width, result);
            
            if (heights[start] < heights[end]) {
                ++start;
            } else {
                --end;
            }
        }

        return result;
    }
};
