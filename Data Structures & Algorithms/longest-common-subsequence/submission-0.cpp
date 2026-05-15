#include <cstring>
class Solution {
public:
    int dp[1001][1001];
    int n;
    int m;
    int solve(string& text1, string &text2, int i, int j){
        if(i>=n || j>=m)
        return 0;
        
        if(text1[i]==text2[j])
        return 1+solve(text1, text2,i+1,j+1);

        if(dp[i][j]!=-1)
        return dp[i][j];

        int take=solve(text1, text2, i+1,j);
        int skip=solve(text1, text2,i, j+1);

        return dp[i][j]=max(take,skip);
    }
    int longestCommonSubsequence(string text1, string text2) {
        n=text1.size();
        m=text2.size();
        memset(dp, -1,sizeof(dp));
        return solve(text1, text2,0,0);
    }
};
