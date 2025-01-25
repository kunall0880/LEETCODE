class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& vec, int limit) {
        int n=vec.size();
        vector<int>nums=vec;
        sort(nums.begin(),nums.end());
        int count=0;
        unordered_map<int,list<int>>grp;
        unordered_map<int,int>who;
        who[nums[0]]=count;
        grp[count].push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(abs(nums[i]-nums[i-1])>limit){
                count++;
            }
            who[nums[i]]=count;
            grp[count].push_back(nums[i]);
        }
        for(int i=0;i<n;i++){
            int num=vec[i];
            int group=who[num];
            nums[i]=*grp[group].begin();
            grp[group].pop_front();
        }
        return nums;
    }
};
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     while(1){
        //         int smallest=nums[i];
        //         int idx=-1;
        //         for(int j=i+1;j<n;j++){
        //             if(abs(nums[i]-nums[j])<=limit){
        //                 if(nums[j]<smallest){
        //                     idx=j;
        //                 }
        //             }
        //         }
        //         if(idx!=-1){
        //             swap(nums[i],nums[idx]);
        //         }else{
        //             break;
        //         }
        //     }
        // }
        // return nums;