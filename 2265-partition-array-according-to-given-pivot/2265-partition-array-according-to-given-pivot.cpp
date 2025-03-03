class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int count=0;
        int n=nums.size();
        vector<int>left,right;
        for(auto it : nums){
            if(it<pivot){
                left.push_back(it);
            }else if (it>pivot){
                right.push_back(it);
            }else{
                count++;
            }
        }
        while(count--){
            left.push_back(pivot);
        }
        for(auto it : right){
            left.push_back(it);
        }
        return left;
    }
};