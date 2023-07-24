// https://leetcode.com/problems/product-of-array-except-self

vector<int> productExceptSelf(vector<int> &nums)
{
    const int n = nums.size();
    vector<int> result(n, 1);

    int leftProduct = 1;
    for (int i = 0; i < n; ++i)
    {
        result[i] = leftProduct;
        leftProduct *= nums[i];
    }

    int rightProduct = 1;
    for (int i = n - 1; i >= 0; --i)
    {
        result[i] *= rightProduct;
        rightProduct *= nums[i];
    }

    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> res0;
    vector<int> res1;

    {
        vector<int> nums{1, 2, 3, 4};
        res0 = productExceptSelf(nums); // 24, 12, 8, 6
    }
    {
        vector<int> nums{-1, 1, 0, -3, 3};
        res1 = productExceptSelf(nums); // 0, 0, 9, 0, 0
    }

    return 0;
}
