class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //TC = O(n), SC = O(1)
        int n = nums.size();
        int minLength = INT_MAX;
        int left = 0, sum = 0;

        for(int right = 0; right < n; right++)  {
            sum += nums[right];

            while(sum >= target)    {
                minLength = min(minLength, right-left+1);
                sum -= nums[left];
                left++;
            }
        }
        return (minLength == INT_MAX)? 0: minLength;
    }
};