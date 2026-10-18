class Solution {
public:
    bool check(vector<int>& nums) {
        int i, count = 0;
        int len = nums.size();
        for( i = 0; i < len; i++){
            if(nums[i] > nums[(i+1)%len])
            count ++;

        }
        if( count > 1)
        return false;
        else
        return true;
        
    }
};