class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int m=*max_element(arr.begin(),arr.end());
        int j=0,s=k;
        for(int i=1;i<=m+s;i++){
            if(j<arr.size()&&arr[j]==i){
                j++;
            }else{
                k--;
            }
            if(k==0){
                return i;
            }
        }
        return -1;
    }
};