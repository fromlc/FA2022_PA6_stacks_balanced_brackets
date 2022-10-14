//------------------------------------------------------------------------------
// FA2022_PA6_stacks_balanced_brackets.cpp
//
// Author: Gaddis 9E Ch.13 Programming Challenge 15 on p.1222
//------------------------------------------------------------------------------
#include <iostream>
#include <string>

#include "CharStack.h"

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cin;
using std::cout;
using std::string;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int MAX_LEN = 100;

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
static CharStack g_stack;

static const enum g_brackets {
	L_SQUARE = '[',
	R_SQUARE = ']',
	L_CURLY = '{',
	R_CURLY = '}',
	L_PAREN = '(',
	R_PAREN = ')',
};

//------------------------------------------------------------------------------
// test bracket strings
//------------------------------------------------------------------------------
//static const string g_test = "[[]{()}]";
//static const string g_test = "()}";
//static const string g_test = "[";

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
bool getInputString(string& s);
bool balancedBrackets(string&);
bool isMatchingRightBracket(char c);
char cMatch(char c);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

	cout << "\nBracket string balance check\n\n";

	string input;
	while (getInputString(input)) {
		if (!balancedBrackets(input) || !g_stack.isEmpty())
			cout << input << " is NOT balanced\n";
		else
			cout << input << " IS balanced\n";

		g_stack.makeEmpty();
	}
	cout << "\nGoodbye!\n";
}

//------------------------------------------------------------------------------
// returns false if "q" or "Q" entered, true otherwise
//------------------------------------------------------------------------------
bool getInputString(string& s) {
	cout << "\nEnter bracket string: ";
	getline(cin, s);

	return !((bool)!s.compare("q") || (bool)!s.compare("Q"));
}

//------------------------------------------------------------------------------
// returns true if bracket string is balanced, false otherwise
//------------------------------------------------------------------------------
bool balancedBrackets(string& s) {
	// assume balanced string
	bool balanced = true;

	for (char c : s) {
		// push on left bracket
		if (c == L_SQUARE || c == L_CURLY || c == L_PAREN) {
			g_stack.push(c);
		}
		// check for balance on right bracket
		else if (c == R_SQUARE || c == R_CURLY || c == R_PAREN) {
			balanced = isMatchingRightBracket(c);
			if (!balanced) {
				break;
			}
		}
	}
	return balanced;
}

//------------------------------------------------------------------------------
// returns true if current character does not cause imbalance, false otherwise
// 
// in a balanced bracket string, any right bracket must
// have a matching left bracket in the top of the stack
//------------------------------------------------------------------------------
bool isMatchingRightBracket(char c) {
	if (g_stack.isEmpty())
		return false;		// missing left bracket

	if (cMatch(c) == g_stack.peek()) {
		g_stack.pop();
		return true;		// found matching left bracket
	}

	return false;			// all other bracket strings are unbalanced
}

//------------------------------------------------------------------------------
// returns matching bracket character, or passed value as a last resort
//------------------------------------------------------------------------------
char cMatch(char c) {
	// return matching left side
	if (c == R_SQUARE) return L_SQUARE;
	if (c == R_CURLY) return L_CURLY;
	if (c == R_PAREN) return L_PAREN;
	// return matching right side
	if (c == L_SQUARE) return R_SQUARE;
	if (c == L_CURLY) return R_CURLY;
	if (c == L_PAREN) return R_PAREN;
	// last resort returns passed value
	return c;
}
