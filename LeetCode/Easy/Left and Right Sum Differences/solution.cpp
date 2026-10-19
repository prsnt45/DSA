class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int len = nums.size();
        vector<int> leftsum, rightsum, diff(len);
        for(int i = 0; i < len; i++){
            long long sum = 0;
            for(int j = i+1; j < len; j ++){
                sum += nums[j];
            }
            rightsum.push_back(sum);
            sum = 0;
            for(int j = i-1; j >= 0; j--){
                sum += nums[j];
            }
            leftsum.push_back(sum);
        }
        for(int i = 0; i < len; i++){
            diff[i] = abs(rightsum[i] - leftsum[i]);
        }
        return diff;
    }
};