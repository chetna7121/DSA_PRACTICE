class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        map<int, int> prefixProducts; 
        map<int, int> suffixProducts;  
        
        int prefixProduct = 1;
        for (int i = 0; i < n; ++i) {
            prefixProducts[i] = prefixProduct;
            prefixProduct *= nums[i];
        }
        
        int suffixProduct = 1;
        for (int i = n - 1; i >= 0; --i) {
            suffixProducts[i] = suffixProduct;
            suffixProduct *= nums[i];
        }
        
        for (int i = 0; i < n; ++i) {
            result[i] = prefixProducts[i] * suffixProducts[i];
        }
        
        return result;
    }
};
