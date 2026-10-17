class Solution {
public:
    int sumOfSquares(vector<int>& nums) {

        int len = nums.size();
        int sum = 0;
        int arr[len];
        for(int i = 1; i <= len; i++){
            if(len % i == 0){
                int a = nums[i-1];
                sum += a*a;
                
            }
        }
        return sum;
    }
};