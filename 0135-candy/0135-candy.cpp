class Solution {
public:
    int candy(vector<int>& ratings) {
        //TC = O(n), SC = O(n)
        int n = ratings.size();
        if(n == 0)
            return 0;
        
        vector<int> candies(n,1);

        //compare candies while going left to right
        for(int i = 1; i < n; i++)  {
            if(ratings[i] > ratings[i-1])   {
                candies[i] = candies[i-1]+1;
            }
        }
        //compare candies while going right to left
        for(int i = n-2; i >= 0; i--)   {
            if(ratings[i] > ratings[i+1])   {
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }
        //sum the candies of the vector candies
        int totalCandies = 0;
        for(int candy:candies)  {
            totalCandies += candy;
        }
        return totalCandies;
    }
};