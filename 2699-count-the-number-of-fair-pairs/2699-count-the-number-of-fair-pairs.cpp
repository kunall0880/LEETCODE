class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int low = lower - nums[i];
            int up = upper - nums[i];
            int a = (lower_bound(begin(nums) + i + 1, end(nums),low))-nums.begin();
            int x=a-i-1;
            a =(upper_bound(begin(nums) + i + 1, end(nums),up))-nums.begin();
            int y=a-i-1;
            count += (y - x);
        }
        return count;
    }
};