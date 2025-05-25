class Solution {
public:
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        int n = nums.size();
        vector<long long int> leftProduct(n, 1), rightProduct(n, 1), result(n);
        for (int i = 1; i < n; ++i) {
            leftProduct[i] = leftProduct[i - 1] * nums[i - 1];
        }
        long long rightProductAcc = 1;
        for (int i = n - 1; i >= 0; --i) {
            result[i] = leftProduct[i] * rightProductAcc;
            rightProductAcc *= nums[i];
        }

        return result;
    }
};
