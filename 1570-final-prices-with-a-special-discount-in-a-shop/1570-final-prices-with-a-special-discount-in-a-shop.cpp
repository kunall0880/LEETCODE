class Solution {
public:
    int findmin(vector<int>nums,int val,int index){
        for(int idx=index+1;idx<nums.size();idx++){
            if(nums[idx]<=val){
                return nums[idx];
            }
        }
        return -1;
    }
    vector<int> finalPrices(vector<int>& nums) {
           vector<int>ret;
           int n=nums.size();
           for(int i=0;i<n;i++){
            int node = findmin(nums,nums[i],i);
            if(node==-1){
                ret.push_back(nums[i]);
                continue;
            }
            ret.push_back(nums[i]-node);
           }
           return ret;
    }
};