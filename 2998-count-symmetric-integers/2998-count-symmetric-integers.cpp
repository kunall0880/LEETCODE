class Solution {
public:
    int sum(string str){
        int ans=0;
        for(auto it : str){
            int digit=it-'0';
            ans+=digit;
        }
        return ans;
    }
    int solve(int lim){
        int count=0;
        for(int i=0;i<=lim;i++){
            string str = to_string(i);
            string str1,str2;
            int len=str.length();
            if(len%2!=0){
                continue;
            }
            str1=str.substr(0,len/2);
            str2=str.substr(len/2,len/2);
            if(sum(str1)==sum(str2)){
                count++;
            }
        }
        return count;
    }
    int countSymmetricIntegers(int low, int high) {
        return solve(high)-solve(low-1);
    }
};