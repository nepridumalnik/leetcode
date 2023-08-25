// https://leetcode.com/problems/evaluate-reverse-polish-notation

int evalRPN(vector<string> &tokens)
{
    static const auto isOperation = [](const string &data) -> bool
    {
        static const string operations = "+-*/";
        return operations.find(data) != string::npos;
    };

    stack<int> nums;

    for (const auto &token : tokens)
    {
        if (!isOperation(token))
        {
            nums.push(stoi(token));
            continue;
        }

        int b = nums.top();
        nums.pop();
        int a = nums.top();
        nums.pop();

        int result = 0;

        switch (token.front())
        {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = a / b;
            break;
        }

        nums.push(result);
    }

    return nums.top();
}

int main(int argc, char const *argv[])
{
    int res0 = 0;
    int res1 = 0;
    int res2 = 0;

    {
        vector<string> tokens{"2", "1", "+", "3", "*"};
        res0 = evalRPN(tokens); // 9
    }
    {
        vector<string> tokens{"4", "13", "5", "/", "+"};
        res1 = evalRPN(tokens); // 6
    }
    {
        vector<string> tokens{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
        res2 = evalRPN(tokens); // 22
    }

    return 0;
}
