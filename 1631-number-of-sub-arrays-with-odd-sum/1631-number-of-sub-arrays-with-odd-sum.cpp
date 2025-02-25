class Solution {
public:
    long int MOD=1e9+7;
    int numOfSubarrays(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int sum=0;
        int oddcount=0;
        int evencount=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum%2==0){
                count=(count+oddcount)%MOD;
                evencount++;
            }else{
                count=(count+evencount)%MOD;
                oddcount++;
            }
        }
        return count%MOD;
    }
};