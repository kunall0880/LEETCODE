class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int count=0,ele=-1;
        for(auto it : nums){
            if(count==0){
                ele=it;
            }
            if(it==ele){
                count++;
            }else{
                count--;
            }
        }
        count=0;
        for(auto it : nums){
            if(it==ele){
                count++;
            }
        }int cl=0,cr=0,n=nums.size();
        for(int i=0;i<n;i++){
            int n1=i+1;
            int n2=n-i-1;
            if(nums[i]==ele){
                cl++;
                cr=count-1;
                count--;
            }
            if(2*cl>n1&&2*cr>n2){
                return i;
            }
        }
        return -1;
    }
};


    // unordered_map<int,int>map1,map2;
    //         for(auto it : nums){
    //             map2[it]++;
    //         }
    //         int n=nums.size();
    //         for(int i=0;i<n;i++){
    //             map1[nums[i]]++;
    //             map2[nums[i]]--;
    //             int n1=i+1;
    //             int n2=n-i-1;
    //             if(2*map1[nums[i]]>n1&&2*map2[nums[i]]>n2){
    //                 return i;
    //             }
    //         }
    //         return -1;