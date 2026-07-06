#include <cstring>
class Solution {
public:
    int dp[46];
    int solve(int n, int i){
        if(i>n)
        return 0;

        if(i==n)
        return 1;

        if(dp[i]!=-1)
        return dp[i];

        int take=solve(n,i+1);
        int skip=solve(n,i+2);

        return dp[i]=take+skip;
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        if(n==1 || n==2)
        return n;

        return solve(n,0);
    }
};
