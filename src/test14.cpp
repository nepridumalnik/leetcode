// https://leetcode.com/problems/product-of-array-except-self

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> simpleDigits;
    simpleDigits.resize(nums.size());

    for (size_t i = 0; i < simpleDigits.size(); ++i)
    {
        int prod = 1;
        for (size_t j = 0; j < nums.size(); ++j)
        {
            if (j == i)
            {
                continue;
            }
            else if (nums[j] == 0)
            {
                prod = 0;
                break;
            }

            prod *= nums[j];
        }

        simpleDigits[i] = prod;
    }

    return simpleDigits;
}

int main(int argc, char const *argv[])
{
    vector<int> res0;
    vector<int> res1;
    // vector<int> res2;

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
