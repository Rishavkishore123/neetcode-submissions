#include<cstring>
class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int solve(int j,vector<int>& coins,int i){

        

        if(i>=n)
        return 0;

        if(j==0)
        return 1;

        if(dp[i][j]!=-1)
        return dp[i][j];

        int take=0;
        if(j>=coins[i])
        take=solve(j-coins[i], coins, i);

        int skip=solve(j, coins, i+1);

        return dp[i][j]=take + skip;
    }
    int change(int amount, vector<int>& coins) {
        n= coins.size();
        dp.resize(n + 1, vector<int>(amount + 1, -1));
        return solve(amount, coins, 0);
    }
};
