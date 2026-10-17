class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int len = nums.size();

        vector<pair<int, int>> arr;

        for (int i = 0; i < len; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end(), [](auto a, auto b) {
            int sumA = 0, sumB = 0;
            int x = a.first, y = b.first;

            while (x > 0) {
                sumA += x % 10;
                x /= 10;
            }

            while (y > 0) {
                sumB += y % 10;
                y /= 10;
            }

            if (sumA == sumB)
                return a.first < b.first;

            return sumA < sumB;
        });

        vector<bool> visited(len, false);
        int swaps = 0;

        for (int i = 0; i < len; i++) {
            if (visited[i] || arr[i].second == i)
                continue;

            int j = i;
            int cycleSize = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].second;
                cycleSize++;
            }

            swaps += cycleSize - 1;
        }

        return swaps;
    }
};