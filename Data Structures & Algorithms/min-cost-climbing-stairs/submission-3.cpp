#include<cstring>
class Solution {
public:
        int n;
        int dp[101];
    int solve(vector<int>& cost, int i){
        if(i>=n)
        return 0;

        // if(n==2)
        // return n;

        if(dp[i]!=-1)
        return dp[i];

        int take=cost[i]+solve(cost,i+1);
        int skip=cost[i]+solve(cost,i+2);

        return dp[i]=min(take, skip);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size();
        memset(dp,-1,sizeof(dp));
        return min(solve(cost, 0), solve(cost, 1));
    }
};
