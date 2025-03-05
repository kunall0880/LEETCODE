class Solution {
public:
    long long coloredCells(int n) {
    if(n==1){
        return 1;
    }
    long long ans=1;
    for(int i=1;i<n;i++){
       long long power=4*i;
       ans=ans+power;
    }
    return ans;   
    }
};