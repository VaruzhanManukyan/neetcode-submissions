class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int current = arr[arr.size() - 1];
        arr[arr.size() - 1] = -1;
        
        for(int i = static_cast<int>(arr.size()) - 2; i >= 0; --i) {
            if (arr[i] > current) {
                std::swap(arr[i], current);
            } else {
                arr[i] = current;
            }
        }

        return arr;
    }
};