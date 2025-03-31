class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<int>nums(n-1,0);
        for(int i=0;i<n-1;i++){
            nums[i]=(weights[i]+weights[i+1]);
        }
        sort(nums.begin(),nums.end());
        long long fm=0,lm=0;
        n=nums.size();
        for(int i=0;i<k-1;i++){
            fm+=nums[i];
            lm+=nums[n-i-1];
        }
        return (lm-fm);
    }
};