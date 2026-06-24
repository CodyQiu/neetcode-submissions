class Solution {
public:

    int compute(int a, int b, string op)  {
        if (op == "+") {
            return a + b;
        } else if (op == "-") {
            return b - a;
        } else if (op == "/") {
            return b / a;
        } else if (op == "*") {
            return b * a;
        }
        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        stack<string> numbers;
        // for (string token: tokens) {
        //     if (token == "+" || token == "-" || token == "*" || token == "/") {
        //         operators.push(token);
        //     } else {
        //         numbers.push(token);
        //     }
        // }
        int result;

        for (string token: tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int a = stoi(numbers.top());
                numbers.pop();
                int b = stoi(numbers.top());
                numbers.pop();
                result = compute(a, b, token);
                numbers.push(to_string(result));
            }
            else numbers.push(token);
        }
        return stoi(numbers.top());
    }
};
