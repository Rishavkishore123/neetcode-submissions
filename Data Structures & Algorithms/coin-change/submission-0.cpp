class Solution {
public:
    int n;

    int solve(vector<int>& coins, int i, int amount){

        if(amount==0)
        return 0;

        if(i==n)
        return 1e9;

        if(coins[i]> amount)
        return solve(coins, i+1, amount);

        int take=1+solve(coins, i, amount-coins[i]);
        int skip=solve(coins, i+1, amount);


        return min(take, skip);


    }

    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();

        int ans= solve(coins, 0, amount);

        return (ans>=1e9) ? -1:ans;
    }
};
