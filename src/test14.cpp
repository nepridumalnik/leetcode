// https://leetcode.com/problems/product-of-array-except-self

vector<int> productExceptSelf(vector<int> &nums)
{
    const int n = nums.size();
    vector<int> result;
    result.resize(n, 1);

    int tmpProduct = 1;
    for (int i = 0; i < n; ++i)
    {
        result[i] = tmpProduct;
        tmpProduct *= nums[i];
    }

    tmpProduct = 1;
    for (int i = n - 1; i >= 0; --i)
    {
        result[i] *= tmpProduct;
        tmpProduct *= nums[i];
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
