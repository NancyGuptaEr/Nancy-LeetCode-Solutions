class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int answer = 1;
        int n = nums.size();
        if(n == 0)  {
            return 0;
        }
        for(int i = 1; i < n; i++)    {
            if(nums[i] != nums[i-1])  {
                nums[answer] = nums[i];
                answer++;
            }
        }
        return answer;
    }
};

//time complexity = O(n), SC = O(1)