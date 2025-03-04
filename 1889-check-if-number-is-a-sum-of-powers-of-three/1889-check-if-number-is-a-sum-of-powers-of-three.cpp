class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n>0){
            int a=n%3;
            cout<<a<<endl;
            n=n/3;
            if(a!=0 && a!=1){
                return false;
            }
        }
        return true;
    }
};


/*
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
*/