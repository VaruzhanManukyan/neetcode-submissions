class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (std::size_t i = 0; i < matrix.size(); ++i) {
            if (matrix[i][matrix[i].size() - 1] < target) {
                continue;
            }

            if (matrix[i][0] > target) {
                return false;
            }

            int left = 0;
            int right = matrix[i].size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (matrix[i][mid] == target) {
                    return true;
                }

                if (matrix[i][mid] > target) {
                    right = --mid;
                } else {
                    left = ++mid;
                }
            }
        }

        return false;
    }
};
