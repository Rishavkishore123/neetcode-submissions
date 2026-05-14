#include<cstring>
class Solution {
public:
    int dp[101][101];
    int solve(int m, int n , int i, int j){
        if(i>=m || j>=n)
        return 0;
        // base case

        if(i==m-1 && j==n-1)
        return 1;

        if(dp[i][j]!=-1)
        return dp[i][j];

        int take_right=0, take_down=0;
        if(i+1<m)
        take_down=solve(m,n,i+1,j);

        if(j+1<n)
        take_right=solve(m,n,i,j+1);

        return dp[i][j]=take_down + take_right;

    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(m,n,0,0);
    }
};
