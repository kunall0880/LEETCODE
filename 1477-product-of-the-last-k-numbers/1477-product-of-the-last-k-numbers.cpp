class ProductOfNumbers {
public:
    vector<int>nums;
    int total=1;
    vector<int>pre;
    ProductOfNumbers() {}
    
    void add(int num) {
        nums.push_back(num);
        if(num==0){
            total=1;
            pre.erase(pre.begin(),pre.end());
            return;
        }
        total*=num;
        pre.push_back(total);
    }
    
    int getProduct(int k) {
        int n=pre.size();
        if(k>n){
            return 0;
        }
        if(n-k-1<0){
            return pre.back();
        }
        else{
            return (pre.back()/pre[n-k-1]);
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */