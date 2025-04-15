class Solution {
public:
    void updateSegment(int i,int l ,int r, int idx,vector<long long>&segment){
        if(l==r){
            segment[i]=1;
            return;
        }
        int mid = l+(r-l)/2;
        if(idx<=mid){
            updateSegment(2*i+1,l,mid,idx,segment);
        }else{
            updateSegment(2*i+2,mid+1,r,idx,segment);
        }
        segment[i]=segment[2*i+1]+segment[2*i+2];
    }
    long long querry(int qs,int qe,int i,int l,int r,vector<long long>&segment){
        if(r<qs||l>qe){
            return 0;
        }
        if(l>=qs&&r<=qe){
            return segment[i];
        }
        int mid=l+(r-l)/2;
        long long left = querry(qs,qe,2*i+1,l,mid,segment);
        long long right = querry(qs,qe,2*i+2,mid+1,r,segment);
        return left+right;
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            mp[nums2[i]]=i;
        }
        vector<long long>segment(4*n);
        long long result=0;
        updateSegment(0,0,n-1,mp[nums1[0]],segment);
        for(int i=1;i<n;i++){
            int idx = mp[nums1[i]];
            long long leftCommon = querry(0,idx,0,0,n-1,segment);
            long long leftnotCommon = i-leftCommon;

            long long elementAfterIdxNums2 = (n-1)-idx;
            long long rightCommonCount = elementAfterIdxNums2-leftnotCommon;

            result+=leftCommon*rightCommonCount;
            updateSegment(0,0,n-1,idx,segment);
        }
        return result;
    }
};