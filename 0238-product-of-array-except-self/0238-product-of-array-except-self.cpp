class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //TC=O(n), SC=O(n)
        int n = nums.size();
        if (nums.empty()) {
            return {};
        }
        if (nums.size() == 1) {
            return {1};
        }
        vector<int> output(n);

        //initialise the first elemen of output as 1
        output[0] = 1;
        //calculate the left products
        for(int i = 1; i < n; i++)  {
            output[i] = output[i-1]*nums[i-1];
        }

        int right = 1;
        //calculate the right products
        for(int i = n-1; i >= 0; i--)   {
            output[i] = output[i] * right;
            right *= nums[i];
        }
        return output;
    }
};

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         //TC=O(n^2), SC=O(n)
//         int n = nums.size();
//         vector<int> output;
//         for(int i = 0; i < n; i++)  {
//             int product = 1;
//             for(int j = 0; j < n; j++)  {
//                 if(i == j)
//                     continue;
//                 product *= nums[j];
//             }
//             output.push_back(product);
//         }
//         return output;
//     }
// };