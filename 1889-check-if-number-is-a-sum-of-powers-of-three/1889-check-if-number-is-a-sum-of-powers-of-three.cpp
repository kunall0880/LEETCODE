class Solution {
public:
    bool checkPowersOfThree(int n) {
        int power=0,ans=1;
        while(pow(3,power)<=n){
            power++;
        }
        while(n>=0&&power>=0){
            ans=pow(3,power);
            if(n>=ans){
                n-=ans;
            }power--;
        }
        if(n==0){
            return true;
        }
        return false;
    }
};