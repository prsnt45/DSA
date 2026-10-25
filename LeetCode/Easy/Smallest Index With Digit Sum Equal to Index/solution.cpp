class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int sum = 0;
            int x = nums[i];
            while(x > 0){
                int a = x%10;
                sum += a;
                x = x/10;
            }
            if(sum == i)
            return i;
        }
        return -1;
        
    }
};