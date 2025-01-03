class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int count=0;
        long ls=0,rs=0;
        for(int i=0;i<n-1;i++){
            ls+=nums[i];
            rs=sum-ls;
            if(ls>=rs){
                count++;
            }
        }
        return count;
    }
};