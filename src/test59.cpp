// https://leetcode.com/problems/search-a-2d-matrix

int binarySearch(const vector<int> &v, int target)
{
	if (v.empty())
	{
		return -1;
	}

	int left = 0;
	int right = v.size() - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (v[mid] == target)
		{
			return 0;
		}
		else if (v[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	if (*v.begin() > target)
		return -1;

	return 1;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
	if (matrix.empty())
	{
		return false;
	}

	int left = 0;
	int right = matrix.size() - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		auto &v = matrix[mid];
		int res = binarySearch(v, target);

		if (0 == res)
		{
			return true;
		}
		else if (res == 1)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return false;
}

void checkBinarySearch()
{
	vector<int> v;

	for (size_t i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (binarySearch(v, i))
		{
			return;
		}
	}

	for (size_t i = 0; i < v.size(); ++i)
	{
		if (binarySearch(v, i))
		{
			return;
		}
	}
}

int main(int argc, char const *argv[])
{
	checkBinarySearch();

	int target1 = 3; // true
	vector<vector<int>> matrix1{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
	int target2 = 13; // false
	vector<vector<int>> matrix2{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
	int target3 = 20; // true
	vector<vector<int>> matrix3{{1, 3, 5, 7}, {10, 11, 16, 20}};
	int target4 = 34; // true
	vector<vector<int>> matrix4{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
	int target5 = 25; // false
	vector<vector<int>> matrix5{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
	int target6 = 7; // true
	vector<vector<int>> matrix6{{1, 3, 5, 7}, {10, 11, 16, 20}};
	int target7 = 2; // false
	vector<vector<int>> matrix7{{1}, {3}};

	bool result1 = searchMatrix(matrix1, target1);
	bool result2 = searchMatrix(matrix2, target2);
	bool result3 = searchMatrix(matrix3, target3);
	bool result4 = searchMatrix(matrix4, target4);
	bool result5 = searchMatrix(matrix5, target5);
	bool result6 = searchMatrix(matrix6, target6);
	bool result7 = searchMatrix(matrix7, target7);

	return 0;
}