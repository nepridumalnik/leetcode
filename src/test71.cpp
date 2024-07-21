// https://leetcode.com/problems/is-subsequence

bool isSubsequence(string s, string t)
{
	size_t counter = 0;

	for (size_t i = 0, j = 0; i < t.size() && counter < s.size(); ++i)
	{
		if (t[i] == s[j])
		{
			++j;
			++counter;
		}
	}

	return counter == s.size();
}

int main(int argc, char const *argv[])
{
	bool result1 = isSubsequence("abc", "ahbgdc");
	bool result2 = isSubsequence("axc", "ahbgdc");

	return 0;
}
