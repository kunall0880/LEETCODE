class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>nums(n,0);
        int cumv=0,cums=0;
        for(int i=0;i<n;i++){
            nums[i]=cums;
            cumv+=boxes[i]-'0';
            cums+=cumv;
        }
        cumv=0,cums=0;
        for(int i=n-1;i>=0;i--){
            nums[i]+=cums;
            cumv+=boxes[i]-'0';
            cums+=cumv;
        }
        return nums;
    }
};