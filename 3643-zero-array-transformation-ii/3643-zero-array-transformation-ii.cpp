class Solution {
public:
    int n;
    int Q;
    bool check(vector<int>nums,vector<vector<int>>queries,int k){
        vector<int>dif(n,0);
        for(int i=0;i<=k;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int val=queries[i][2];

            dif[l]+=val;
            if(r+1<n){
                dif[r+1]-=val;
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=dif[i];
            dif[i]=sum;

            if(nums[i]-dif[i]>0){
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        Q=queries.size();
        n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count++;
            }
        }
        if(count==n){
            return 0;
        }
        int l=0,h=Q-1,k=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(check(nums,queries,mid)){
                k=mid+1;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return k;
    }
};