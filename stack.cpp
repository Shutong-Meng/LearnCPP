#include <iostream>
using namespace std;

#include <string>
#include <stack>//include head file

class Solution {
public:
	bool isValid(string s) {
		if (s.empty()) return true;//if input is emptys

		stack<char> my_stack;
		for (int i = 0; i < s.size(); i++)
		{
			if (isLeft(s[i])) my_stack.push(s[i]);
			else
			{
				if (my_stack.empty()) return false;
				else
				{
					if (isMatch(my_stack.top(), s[i])) my_stack.pop();
					else return false;
				}
			}
		}
		if (my_stack.empty()) return true;
		else return false;
	}
public:
	bool isMatch(char a, char b)
	{
		return ((a == '('&&b == ')') || (a == '['&&b == ']') || (a == '{'&&b == '}'));
	}
	bool isLeft(char a)
	{
		return (a == '(' || a == '[' || a == '{');
	}
};