#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
	std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
		int n = temperatures.size();

		std::vector<int> answer(n, 0);

		std::stack<int> greaterTempIndexes_stack;


		for (int i = (n - 1); i >= 0; --i) {
			while ((!greaterTempIndexes_stack.empty()) && (temperatures[greaterTempIndexes_stack.top()] <= temperatures[i])) {
				greaterTempIndexes_stack.pop();
			};


			if (!greaterTempIndexes_stack.empty()) {
				answer[i] = greaterTempIndexes_stack.top() - i;
			};



			greaterTempIndexes_stack.push(i);
		};



		return answer;
	};
};



int main(void) {
	std::vector<int> temp = { 73,74,75,71,69,72,76,73 };

	Solution s;

	std::vector<int> nextGreaterTemp = s.dailyTemperatures(temp);

	for (int i = 0; i < nextGreaterTemp.size(); i++) {
		std::cout << nextGreaterTemp[i] << " ";
	};
	
	return 0;
}