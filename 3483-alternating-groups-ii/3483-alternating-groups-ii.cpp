class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums, int k) {
         int n=nums.size();
        for(int i=0;i<k-1;i++){
            nums.push_back(nums[i]);
        }
        int count=0;
        int i=0,j=1;
        int N=n+(k-1);
        while(j<N){
            if(nums[j-1]==nums[j]){
                i=j;
                j++;
                continue;
            }
            if(j-i+1==k){
                i++;
                count++;
            }
            j++;
        }
        return count;
    }
};




// TLE  
// int n=nums.size();
//         for(int i=0;i<k-1;i++){
//             nums.push_back(nums[i]);
//         }
//         int count=0;
//         for(int i=0;i<n;i++){
//             int f=1;
//             for(int j=i+1;j<i+k;j++){
//                 if(nums[j]==nums[j-1]){
//                     f=0;
//                     break;
//                 }
//             }
//             if(f){
//                 count++;
//             }
//         }
//         return count;