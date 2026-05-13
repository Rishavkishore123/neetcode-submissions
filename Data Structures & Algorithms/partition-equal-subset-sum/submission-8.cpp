#include <cstring>
class Solution {
public:
    int dp[101][101];
    int n;
    bool solve(vector<int>& nums, int i, int current){
        if(current==0)
        return true;

        if(i>=n)
        return false;

        if(dp[i][current]!=-1)
        return dp[i][current];

        bool take=false; 
        if(current>=nums[i])
        take=solve(nums,i+1, current-nums[i]);

        bool skip=solve(nums,i+1,current);

        return dp[i][current]= take || skip;
    }
    bool canPartition(vector<int>& nums) {
        n=nums.size();
        int sum=0;

        memset(dp,-1,sizeof(dp));

        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        if(sum%2!=0)
        return false;

        return solve(nums,0,sum/2);
    }
};
