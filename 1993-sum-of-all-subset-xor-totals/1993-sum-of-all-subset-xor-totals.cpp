class Solution {
public:
    // int gensub(vector<int>&nums,int idx,int x){
    //     if(idx==nums.size()){
    //         return x;
    //     }
    //     int take=gensub(nums,idx+1,x^nums[idx]);
    //     int nottake=gensub(nums,idx+1,x);
    //     return (take+nottake);
    // }
    int subsetXORSum(vector<int>& nums) {
        //return gensub(nums,0,0);
        int Or=0,n=nums.size();
        for(auto it :nums){
            Or=Or|it;
        }
        return (Or<<(n-1));
    }
};