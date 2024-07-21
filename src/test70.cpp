// https://leetcode.com/problems/valid-palindrome/?envType=study-plan-v2&envId=top-interview-150

bool isPalindrome(string s)
{
	int l = 0;
	int r = s.size() - 1;
	while (l <= r)
	{
		if (!isalpha(s[l]) && !isdigit(s[l]))
		{
			++l;
			continue;
		}
		if (!isalpha(s[r]) && !isdigit(s[r]))
		{
			--r;
			continue;
		}

		if (tolower(s[l]) != tolower(s[r]))
		{
			return false;
		}

		++l;
		--r;
	}

	return true;
}

int main(int argc, char const *argv[])
{
	bool result1 = isPalindrome("A man, a plan, a canal: Panama");
	bool result2 = isPalindrome("0P");

	return 0;
}
