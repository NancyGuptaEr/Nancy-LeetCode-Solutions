class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //solve using Boyer-Moore voting algorithm
        //TC = O(n), SC = O(1)
        if (nums.empty()) {
            return -1; // or some other indication of invalid input
        }
        int count = 0;
        int candidate = 0;
        for(int num:nums)  {
            if(count == 0)  {
                candidate = num;
                count++;
            }
            else if(num == candidate)     {
                count++;
            }
            else    {
                count--;
            }
        }
        return candidate;
    }
};

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         //TC = O(n log n), SC = O(n)
//         int n = nums.size();
//         map<int, int> M;
//         for(int i = 0; i< n; i++)   {
//             M[nums[i]]++;
//             if(M[nums[i]] > n/2)    {
//                 return nums[i];
//             }
//         }
//         return -1;
//     }
// };