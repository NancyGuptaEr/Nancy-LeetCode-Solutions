class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //time complexity = O(m+n), space complexity = O(1)
        // this is more optimized solution
        int answerIndex = m+n-1;    //last position in nums1
        int index1 = m-1;
        int index2 = n-1;

        //merge 2 srted arrays
        while(index1 >=0 && index2 >= 0) {
            if(nums1[index1] > nums2[index2]) {
                nums1[answerIndex--] = nums1[index1--];
            }
            else    {
                nums1[answerIndex--] = nums2[index2--];
            }
        }
        while(index2 >= 0)   {
                nums1[answerIndex--] = nums2[index2--];
            }
    }
};


// void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         for(int j = 0; i = m, j < n; j++)   {
//             nums1[i] = nums2[j];
//             i++;
//         }
//         sort(nums1.begin(), nums2.end());
// }

//time complexity = O((m+n)log(m+n))