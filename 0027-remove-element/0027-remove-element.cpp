class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int answer = 0; //expected k value to be returned
        if(nums.empty())    {
            return 0;
        }
        for(int  i = 0; i < nums.size(); i++)   {
            if(nums[i] != val)  {
                nums[answer] = nums[i];
                answer++;
            }
        }
        return answer;
    }
};

//time complexity = O(n), space complexity = O(1)