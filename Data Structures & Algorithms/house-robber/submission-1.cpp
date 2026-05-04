#include <cstring>
class Solution {
public:
/*
approach




*/
    int dp[101];
    int solve(vector<int>& nums, int i){
        if(i>=nums.size())
        return 0;

        // if(n==1)
        // return nums[i];
        if(dp[i]!=-1)
        return dp[i];

        int take= nums[i]+solve(nums, i+2);
        int skip=  solve(nums,i+1);

        return dp[i]=max(take, skip);
    }
    int rob(vector<int>& nums) {
       // n=nums.size();
       memset(dp,-1,sizeof(dp));
        return solve(nums, 0);
    }
};
