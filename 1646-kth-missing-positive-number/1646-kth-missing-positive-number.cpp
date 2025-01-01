class Solution {
public:
    int bin(int k,int low,int high ,vector<int>arr){
        int mid=(low+high)/2;
        while(low<=high){
            mid=(low+high)/2;
            if((arr[mid]-(mid+1)) < k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low+k;
    }
    int findKthPositive(vector<int>& arr, int k) {
        return bin(k,0,arr.size()-1,arr);
    }
};