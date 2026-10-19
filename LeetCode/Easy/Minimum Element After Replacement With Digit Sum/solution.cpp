class Solution {
public:
    int minElement(vector<int>& nums) {
        vector<int> arr;
        for(int i = 0; i < nums.size(); i++){
            int n = nums[i];
            int sum = 0;
            while(n > 0){
                int a = n%10;
                sum += a;
                n = n/10;
                
            }
            arr.push_back(sum);
        }
        sort(arr.begin(), arr.end());

        int min = arr[0];
        return min;
        
        
    }
};