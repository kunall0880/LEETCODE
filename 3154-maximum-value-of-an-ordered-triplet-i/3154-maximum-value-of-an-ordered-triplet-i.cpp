class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    long long cal1=nums[i]-nums[j];
                    long long cal2=cal1*nums[k];
                    ans=max(ans,cal2);
                }
            }
        }
        return ans>0?ans:0;
    }
};