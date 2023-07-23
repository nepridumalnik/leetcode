#include <algorithm>
#include <set>
#include <vector>

// https://leetcode.com/problems/median-of-two-sorted-arrays/
double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
{
    nums1.reserve(nums1.size() + nums2.size());
    for (size_t i = 0; i < nums2.size(); ++i)
    {
        nums1.push_back(nums2[i]);
    }

    std::sort(nums1.begin(), nums1.end(), std::less<int>());

    if (0 == (nums1.size() % 2))
    {
        const size_t median = (nums1.size() / 2);
        const int x = nums1[median];
        const int y = nums1[median - 1];
        const double result = static_cast<double>(x + y) / 2;
        return result;
    }

    const size_t median = (nums1.size() / 2);
    return nums1[median];
}

int main(int argc, char const *argv[])
{
    {
        auto vec1 = std::vector<int>{1, 3};
        auto vec2 = std::vector<int>{2};
        auto res0 = findMedianSortedArrays(vec1, vec2);
    }

    {
        auto vec1 = std::vector<int>{1, 2};
        auto vec2 = std::vector<int>{3, 4};
        auto res1 = findMedianSortedArrays(vec1, vec2);
    }

    {
        auto vec1 = std::vector<int>{1, 3};
        auto vec2 = std::vector<int>{2, 7};
        auto res2 = findMedianSortedArrays(vec1, vec2);
    }

    return 0;
}
