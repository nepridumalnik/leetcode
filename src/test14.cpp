// https://leetcode.com/problems/product-of-array-except-self

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> rProduct;
    vector<int> lProduct;

    rProduct.resize(nums.size());
    lProduct.resize(nums.size());

    rProduct.back() = 1;

    for (size_t i = 1; i < nums.size(); ++i)
    {
        const size_t rPrev = nums.size() - i;
        rProduct[rPrev - 1] = rProduct[rPrev] * nums[rPrev];
    }

    lProduct.front() = 1;

    for (size_t i = 1; i < nums.size(); ++i)
    {
        const size_t lPrev = i - 1;
        lProduct[i] = lProduct[lPrev] * nums[lPrev];
        lProduct[i - 1] *= rProduct[i - 1];
    }

    return lProduct;
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
