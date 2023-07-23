#include <vector>

using namespace std;

// https://leetcode.com/problems/concatenation-of-array/
vector<int> getConcatenation(vector<int> &nums)
{
    const unsigned short size = nums.size();
    nums.reserve(size);

    unsigned short i = 0;
    do
    {
        nums.push_back(nums[i]);
    } while (++i < size);

    return nums;
}

int main(int argc, char const *argv[])
{
    {
        auto vec = std::vector<int>{1, 2, 1};
        auto res = getConcatenation(vec);
    }
    {
        auto vec = std::vector<int>{1, 2, 3};
        auto res2 = getConcatenation(vec);
    }
    {
        auto vec = std::vector<int>{1, 3, 2, 1};
        auto res3 = getConcatenation(vec);
    }

    return 0;
}
