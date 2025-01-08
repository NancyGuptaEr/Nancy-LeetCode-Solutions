class Solution {
public:
    int hIndex(vector<int>& citations) {
        //TC = O(n log n), SC = O(1)
        int low = 0;
        int high = *max_element(citations.begin(), citations.end());
        int ans = -1;
        while(low <= high)  {
            int mid = low + (high - low) / 2;
            int count = 0;
            for(auto it:citations)  {
                if(it >= mid)   {
                    count++;
                }
            }
            if(count>=mid)  {
                ans = mid;
                low = mid+1;
            }
            else    {
                high = mid-1;
            }
        }
        return ans;
    }
};