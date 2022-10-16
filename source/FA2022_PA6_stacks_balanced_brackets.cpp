//------------------------------------------------------------------------------
// FA2022_PA6_stacks_balanced_brackets.cpp
// 
// Checks a bracket string for balance, ignores all other characters.
// Bracket characters supported: []{}()<>
//
// Author: Gaddis 9E Ch.13 Programming Challenge 15 on p.1222
//------------------------------------------------------------------------------
#include <iostream>
#include <string>

#include "ansi_colors.h"

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
static constexpr int MAX_LEN = 100;
static const string PROMPT = "Enter bracket string to check: ";

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
static CharStack g_stack;

static const enum {		// supported bracket characters
	L_SQUARE = '[',
	R_SQUARE = ']',
	L_CURLY = '{',
	R_CURLY = '}',
	L_PAREN = '(',
	R_PAREN = ')',
	L_ANGLE = '<',
	R_ANGLE = '>',
} g_brackets;

//------------------------------------------------------------------------------
// test bracket strings
//------------------------------------------------------------------------------
static const string testCases[] = { "[[]{()}]", "()}", "[" };

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
void displayBanner();
void checkTestCases();
void inputLoop();
bool getInputString(string& s);
void checkBracketString(string& s);
bool balancedBrackets(string&);
bool validLeftBracket(char c);
bool validRightBracket(char c);
bool isMatchingRightBracket(char c);
char cMatch(char c);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {
	displayBanner();
	checkTestCases();
	inputLoop();		// enter bracket strings, Q or q quits

	return 0;
}

//------------------------------------------------------------------------------
// show app banner and supported bracket characters
//------------------------------------------------------------------------------
void displayBanner() {
	cout << YELLOW << "\nBracket string balance check\n" << RESET_COLORS;
	cout << "\nSupported bracket characters: ";
	cout << (char)L_SQUARE << (char)R_SQUARE;
	cout << (char)L_CURLY << (char)R_CURLY;
	cout << (char)L_PAREN << (char)R_PAREN;
	cout << (char)L_ANGLE << (char)R_ANGLE;
	cout << "\nAll other characters are ignored.\n";
}

//------------------------------------------------------------------------------
// check test cases from PA6 instructions
//------------------------------------------------------------------------------
void checkTestCases() {
	cout << YELLOW << "\nTest cases from PA6 instructions:\n\n"
		<< RESET_COLORS;

	for (string s : testCases) {
		checkBracketString(s);
		cout << '\n';
	}
}

//------------------------------------------------------------------------------
// process user input until user quits
//------------------------------------------------------------------------------
void inputLoop() {
	string input;
	while (getInputString(input)) {
		checkBracketString(input);
	}
	cout << "\nGoodbye!\n";
}

//------------------------------------------------------------------------------
// returns false if "q" or "Q" entered, true otherwise
//------------------------------------------------------------------------------
bool getInputString(string& s) {
	cout << '\n' << PROMPT << YELLOW;
	getline(cin, s);
	cout << RESET_COLORS;

	return !((bool)!s.compare("q") || (bool)!s.compare("Q"));
}

//------------------------------------------------------------------------------
// checks one bracket string for balance
//------------------------------------------------------------------------------
void checkBracketString(string& s) {
	if (!balancedBrackets(s) || !g_stack.isEmpty())
		cout << RED << s << RESET_COLORS << " is not balanced\n";
	else
		cout << YELLOW << s << RESET_COLORS << " is balanced\n";

	// reset stack when done with string
	g_stack.makeEmpty();

}

//------------------------------------------------------------------------------
// returns true if bracket string is balanced, false otherwise
//------------------------------------------------------------------------------
bool balancedBrackets(string& s) {
	// assume balanced string
	bool balanced = true;

	for (char c : s) {
		// push on left bracket
		if (validLeftBracket(c)) {
			g_stack.push(c);
		}
		// check for balance on right bracket
		else if (validRightBracket(c)) {
			balanced = isMatchingRightBracket(c);
			if (!balanced) {
				break;
			}
		}
	}
	return balanced;
}

//------------------------------------------------------------------------------
// returns true on valid left-side bracket, false otherwise
//------------------------------------------------------------------------------
bool validLeftBracket(char c) {
	return c == L_SQUARE || c == L_CURLY || c == L_PAREN || c == L_ANGLE;
}

//------------------------------------------------------------------------------
// returns true on valid right-side bracket, false otherwise
//------------------------------------------------------------------------------
bool validRightBracket(char c) {
	return c == R_SQUARE || c == R_CURLY || c == R_PAREN || c == R_ANGLE;
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
	if (c == R_ANGLE) return L_ANGLE;
	// return matching right side
	if (c == L_SQUARE) return R_SQUARE;
	if (c == L_CURLY) return R_CURLY;
	if (c == L_PAREN) return R_PAREN;
	if (c == L_ANGLE) return R_ANGLE;
	// last resort returns passed value
	return c;
}
