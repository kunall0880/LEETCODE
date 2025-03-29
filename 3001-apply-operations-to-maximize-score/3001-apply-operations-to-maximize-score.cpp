class Solution {
public:
    long int MOD=1e9+7;
    long long find(long long a,long long b){
        if(b==0){
            return 1;
        }
        long long half=find(a,b/2)%MOD;
        long long res = (half % MOD * half % MOD) % MOD;
        if(b%2==1){
            res=(res*a)%MOD;
        }
        return res;
    }
    vector<int> findprime(int lim){
        vector<bool>isprime(lim+1,true);
        vector<int>prime;
        for(long long i=2;i<=lim;i++){
            if(isprime[i]){
                for(long long j=i*i;j<=lim;j+=i){
                    isprime[j]=false;
                }
            }
        }
        for(int i=2;i<=lim;i++){
            if(isprime[i]){
                prime.push_back(i);
            }
        }
        return prime;
    }
    vector<int> findscore(vector<int>nums){
        int n=nums.size();
        vector<int>primescore(n,0);
        int maxele=*max_element(nums.begin(),nums.end());
        vector<int> prime = findprime(maxele);
        for(int i=0;i<n;i++){
            int num=nums[i];
            for(auto it : prime){
                if(it*it >num){
                    break;
                }
                if(num%it!=0){
                    continue;
                }
                primescore[i]++;
                while(num%it==0){
                    num/=it;
                }
            }
            if(num>1){
                primescore[i]++;    
            }
        }
        return primescore;
    }
    vector<int> findnextgreater(vector<int>nums){
        int n=nums.size();
        vector<int> next(n, n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]<=nums[i]){
                st.pop();
            }
            next[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return next;
    }
    vector<int> findprevgreater(vector<int>nums){
        int n=nums.size();
        vector<int> prev(n, -1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums[st.top()]<nums[i]){
                st.pop();
            }
            prev[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return prev;
    }
    int maximumScore(vector<int>& nums, int k) {
        vector<int>score=findscore(nums);
        vector<int>nextgreater=findnextgreater(score);
        vector<int>prevgreater=findprevgreater(score);
        int n=nums.size();
        vector<long long>subarray(n,0);
        for(int i=0;i<n;i++){
            subarray[i]=(long long)(nextgreater[i]-i)*(i-prevgreater[i]);
        }
        vector<pair<int,int>>sortednums(n);
        for(int i=0;i<n;i++){
            sortednums[i]={nums[i],i};
        }
        sort(sortednums.begin(),sortednums.end(),greater<>());
        long long scr=1;
        int idx=0;
        while(k>0){
            auto [num,i]=sortednums[idx];
            long long oper=min((long long)k,subarray[i]);
            scr=scr*find(num,oper)%MOD;
            k=(k-oper);
            idx++;
        }
        return scr;
    }
};