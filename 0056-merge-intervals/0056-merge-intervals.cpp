class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //TC = O(NlogN), SC = O(1)
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        if(n == 0)  {
            return output;
        }
        for(auto interval:intervals)    {
            if(output.empty() || output.back()[1] < interval[0])    {
                output.push_back(interval);
            }
            else    {
                output.back()[1] = max(output.back()[1], interval[1]);
            }
        }
        return output;
    }
};