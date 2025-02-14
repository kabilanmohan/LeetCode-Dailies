class ProductOfNumbers {
public:

    vector<pair<int,int>> prefix;
    long long total_product = 1;
    int zero_count = 0;

    ProductOfNumbers() {
        
    }
    
    void add(int num) 
    {
        if(num == 0)
        {
            zero_count++;
            total_product = 1; // reset product on encountering an zero
            prefix.push_back({total_product , zero_count});
            return;
        }
        total_product *= num;
        prefix.push_back({total_product , zero_count});
    }
    
    int getProduct(int k) 
    {
        int right = prefix.size() - 1;
        int left = right - k;

        if(left < 0) 
        {
            if(prefix[right].second > 0) return 0;
            return total_product;
        }
        if(prefix[left].second != prefix[right].second) return 0;
        return total_product / prefix[left].first;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */


 
