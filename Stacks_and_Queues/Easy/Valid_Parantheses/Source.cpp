#include <iostream>
#include <stack>

class Solution {
	bool isValid(std::string s) {
		std::stack<char> stack;

		for (char i : s) {
			if ((i == '(') || (i == '{') || (i == '[')) {
				stack.push(i);
			}

			else if (stack.empty()) {
				return false;
			}

			else {
				char k = stack.top();

				stack.pop();

				if (((i == ')') && ((k == '{') || (k == '['))) || ((i == '}') && ((k == '(') || (k == '['))) || ((i == ']') && ((k == '(') || (k == '{')))) {
					return false;
				};
			};
		};


		// if the 's' string has only '(', then this will be needed.
		if (stack.empty()) {
			return true;
		};


		return false;
	};
};