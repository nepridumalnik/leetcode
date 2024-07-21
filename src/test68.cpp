// https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150

string reverseWords(string s)
{
	string result;

	for (int end = s.size(), start = end; start > 0;)
	{
		end = s.find_last_not_of(' ', start - 1);
		if (end == -1)
		{
			break;
		}

		start = s.find_last_of(' ', end);

		if (!result.empty())
		{
			result += ' ';
		}

		int st = (start == -1) ? 0 : start + 1;
		int en = end + 1;

		result.append(s.begin() + st, s.begin() + en);
	}

	return result;
}

int main(int argc, char const *argv[])
{
	string result1 = reverseWords("the sky is blue");
	string result2 = reverseWords("  hello world  ");
	string result3 = reverseWords("a good   example");

	return 0;
}
