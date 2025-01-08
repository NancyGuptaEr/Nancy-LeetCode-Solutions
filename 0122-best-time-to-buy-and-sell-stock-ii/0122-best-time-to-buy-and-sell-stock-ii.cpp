class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //TC = O(n), SC = O(1)
        int max_profit = 0;
        int j = 1;
        while(j < prices.size())    {
            if(prices[j] > prices[j-1]) {
                max_profit += prices[j] - prices[j-1];
            }
            j++;
        }
        return max_profit;
    }
};


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         //TC = O(n), SC = O(1)
//         int max_profit = 0;
//         int start = prices[0];
//         for(int i = 1; i < prices.size(); i++)  {
//             if(start < prices[i])   {
//                 max_profit += prices[i] - start;
//             }
//             start = prices[i];
//         }
//         return max_profit;
//     }
// };