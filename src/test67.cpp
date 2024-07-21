// https://leetcode.com/problems/longest-common-prefix/?envType=study-plan-v2&envId=top-interview-150

// TODO: дорешать
string longestCommonPrefix(vector<string> &strs)
{
	if (strs.empty())
	{
		return {};
	}
	else if (strs.size() == 1)
	{
		return strs[0];
	}

	const string &first = strs[0];
}

int main(int argc, char const *argv[])
{
	string result1 = longestCommonPrefix(vector<string>{"flower", "flow", "flight"});

	return 0;
}
