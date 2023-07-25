// https://leetcode.com/problems/move-zeroes1

void moveZeroes(vector<int> &nums)
{
    auto it = remove(nums.begin(), nums.end(), 0);
    fill(it, nums.end(), 0);
}

int main(int argc, char const *argv[])
{
    vector<int> nums0{0, 1, 0, 3, 12}; // 1, 3, 12, 0, 0
    vector<int> nums1{0};              // 0

    moveZeroes(nums0);
    moveZeroes(nums1);

    return 0;
}
