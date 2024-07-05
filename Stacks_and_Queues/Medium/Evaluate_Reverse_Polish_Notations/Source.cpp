#include <iostream>
#include <vector>
#include <stack>
#include <string>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> stack;

        int result;

        for (std::string i : tokens) {
            if (i == "+") {
                int y = stack.top();
                stack.pop();

                int x = stack.top();
                stack.pop();

                result = x + y;

                stack.push(result);
            }

            else if (i == "-") {
                int y = stack.top();
                stack.pop();

                int x = stack.top();
                stack.pop();

                result = x - y;

                stack.push(result);
            }

            else if (i == "*") {
                int y = stack.top();
                stack.pop();

                int x = stack.top();
                stack.pop();

                result = x * y;

                stack.push(result);
            }

            else if (i == "/") {
                int y = stack.top();
                stack.pop();

                int x = stack.top();
                stack.pop();

                result = x / y;

                stack.push(result);
            }

            else {
                stack.push(stoi(i));
            }
        }


        return stack.top();
    }
};