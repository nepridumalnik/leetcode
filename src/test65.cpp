// https://leetcode.com/problems/length-of-last-word/description/?envType=study-plan-v2

int lengthOfLastWord(string s)
{
	auto end = s.find_last_not_of(' ');
	auto start = s.find_last_of(' ', end);

	return end - start;
}

int main(int argc, char const *argv[])
{
	auto res1 = lengthOfLastWord("Hello World");
	auto res2 = lengthOfLastWord("   fly me   to   the moon  ");
	auto res3 = lengthOfLastWord("luffy is still joyboy");

	return 0;
}
