class Solution {
public:
    int bagOfTokensScore(vector<int>& nums, int power) {
        int maxScore=0,n=nums.size(),curr=0;
        int j=n-1,i=0;
        sort(nums.begin(),nums.end());
        while(i<=j){
            if(power>=nums[i]){
                curr++;
                power=power-nums[i];
                maxScore=max(curr,maxScore);
                i++;
            }else if(curr>=1){
                curr--;
                power=power+nums[j];
                j--;
            }else{
                return maxScore;
            }
        }
        return maxScore;
    }
};