class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //TC = O(n), SC = O(1)
        int left = 0;
        int right = numbers.size()-1;
        while(left < right) {
            int total = numbers[left] + numbers[right];
            if(total == target) {
                return {left+1, right+1};
            }
            else if(total < target) {
                left++;
            }
            else    {
                right--;
            }
        }
        return {-1, -1};
    }
};