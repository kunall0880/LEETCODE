class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>dq;
        vector<long long >sum(n,0);
        int j=0,res=INT_MAX;
        while(j<n){
            if(j==0){
                sum[j]=nums[j];
            }else{
                sum[j]=nums[j]+sum[j-1];
            }
            if(sum[j]>=k){
                res=min(res,j+1);
            }
            //shrink
            while(!dq.empty() && sum[j]-sum[dq.front()]>=k ){
                res=min(res,j-dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && sum[j] <= sum[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(j);
            j++;
        }
        if(res==INT_MAX){
            return -1;
        }
        return res;
    }
};