class Solution {
public:
    int trap(vector<int>& height) {
        //TC = O(n), SC = O(n)
        int n = height.size();
        if(n == 0)
            return 0;
        
        vector<int> left(n);
        vector<int> right(n);
        int trappedWater = 0;
        //process the left side
        left[0] = height[0];
        for(int i = 1; i < n; i++)  {
            left[i] = max(left[i-1], height[i]);
        }
        //process the right side
        right[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--)   {
            right[i] = max(right[i+1], height[i]);
        }
        //calculate the trapped water
        for(int i = 0; i < n; i++)  {
            int minHeight = min(left[i], right[i]);
            trappedWater += minHeight - height[i];
        }
        return trappedWater;
    }
};