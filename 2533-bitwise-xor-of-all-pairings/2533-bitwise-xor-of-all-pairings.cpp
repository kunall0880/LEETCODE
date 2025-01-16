class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        int m=nums1.size();
        int n=nums2.size();
        if(n%2==0 && m%2==0){
            ans=0;
        }else if(m%2==0){
            for(int i=0;i<m;i++){
                ans=ans^nums1[i];
            }
        }else if(n%2==0){
            for(int i=0;i<n;i++){
                ans=ans^nums2[i];
            }
        }else{
            int first=0,second=0;
            for(int i=0;i<m;i++){
                first=first^nums1[i];
            }
            for(int i=0;i<n;i++){
                second=second^nums2[i];
            }
            ans=first^second;
        }
        return ans;
    }
};