class Solution {
public:
    int trap(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int result = 0;
        int leftMax = 0;
        int rightMax = 0;

        while (start < end) {
            if (height[start] < height[end]) {
                if (height[start] >= leftMax) {
                    leftMax = height[start];
                } else {
                    result += leftMax - height[start];
                }
                ++start;
            } else {
                if (height[end] >= rightMax) {
                    rightMax = height[end];
                } else {
                    result += rightMax - height[end];
                }
                --end;
            }
        }

        return result;
    }
};