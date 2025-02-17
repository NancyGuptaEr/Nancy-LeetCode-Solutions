//TC = O(m * amount), SC = O(amount)
//m -> no of coins
class Solution {
public:
    int tabulation(vector<int>& coins, int amount)  {
        vector<int> dp(amount+1, INT_MAX);  // Initialize DP array with INT_MAX
        dp[0] = 0;  // Base case: 0 coins needed to make amount 0

        // Iterate over each amount from 1 to the target amount
        for(int val = 1; val <= amount; val++)  {
            for(int i = 0; i < coins.size(); i++)   {
                if(val - coins[i] >= 0 && dp[val - coins[i]] != INT_MAX)    {
                    dp[val] = min(dp[val], 1 + dp[val-coins[i]]);
                }
            }
        }
        // If no solution is found, return -1
        return dp[amount] == INT_MAX? -1 : dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = tabulation(coins, amount);
        // If no solution is found, return -1
        return ans == INT_MAX? -1 : ans;
    }
};