class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        // Case 1: nums is a right rotation of sorted array
        int s = (n - nums[0]) % n;
        bool ok = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (i - s + n) % n) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans = min(s, n - s + 2);
        }

        // Case 2: nums is a rotation of the reversed array
        s = (nums[0] + 1) % n;
        ok = true;

        for (int i = 0; i < n; i++) {
            int j = (i - s + n) % n;

            if (nums[i] != n - 1 - j) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans = min(ans, min(s, n - s) + 1);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};