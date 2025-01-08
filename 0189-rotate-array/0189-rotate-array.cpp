class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n; //ensures that we only perform the necessary minimum rotations
        if(k == 0)  
            return;
        reverse(nums.begin(), nums.end());

        //reverse first k elements
        reverse(nums.begin(), nums.begin()+k);

        //reverse last n-k elements
        reverse(nums.begin()+k, nums.end());
    }
};

//TC = O(n), SC = O(1)