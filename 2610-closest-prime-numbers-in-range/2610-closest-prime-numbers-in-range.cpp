class Solution {
public:
    void fill(vector<bool>&isprime,int right){
        isprime[0]=false;
        isprime[1]=false;

        for(int i=2;i*i<=right;i++){
            if(isprime[i]){
                for(int j=2;i*j<=right;j++){
                    isprime[i*j]=false;
                }
            }
        }
    }
    vector<int> closestPrimes(int left, int right) {
        vector<bool>isprime(right+1,true);
        fill(isprime,right);
        vector<int>prime;
        for(int i=left;i<=right;i++){
            if(isprime[i]){
                prime.push_back(i);
            }
        }
        vector<int>res={-1,-1};
        int differ=INT_MAX;
        for(int i=1;i<prime.size();i++){
            int diff=prime[i]-prime[i-1];
            if(diff<differ){
                res={prime[i-1],prime[i]};
                differ=diff;
            }   
        }
        return res;
    }
};