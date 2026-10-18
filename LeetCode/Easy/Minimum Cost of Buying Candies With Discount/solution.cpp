class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int len = cost.size();
        sort(cost.begin(),cost.end());
        int min = 0;
        for( int i = (cost.size()-1); i >= 0; i--){
           if((cost.size()-1-i)%3 != 2)
           min += cost[i];
        }
        return min;
    }
};