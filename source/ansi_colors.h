//------------------------------------------------------------------------------
// ansi_colors.h
//
// ANSI escape codes for console text and background colors
//------------------------------------------------------------------------------
#ifndef ANSI_COLORS_H
#define ANSI_COLORS_H

// ANSI escape sequences for console text foreground colors
#define BLACK			"\u001b[0;30m"
#define BLACK_BOLD		"\u001b[1;30m"
#define RED				"\u001b[0;31m"
#define RED_BOLD		"\u001b[1;31m"
#define GREEN			"\u001b[0;32m"
#define GREEN_BOLD		"\u001b[1;32m"
#define YELLOW			"\u001b[0;33m"
#define YELLOW_BOLD		"\u001b[1;33m"
#define BLUE			"\u001b[0;34m"
#define BLUE_BOLD		"\u001b[1;34m"
#define MAGENTA			"\u001b[0;35m"
#define MAGENTA_BOLD	"\u001b[1;35m"
#define CYAN			"\u001b[0;36m"
#define CYAN_BOLD		"\u001b[1;36m"
#define WHITE			"\u001b[0;37m"
#define WHITE_BOLD		"\u001b[1;37m"

// ANSI escape sequences for console text background colors
#define BG_BLACK		"\u001b[40m"
#define BG_RED			"\u001b[41m"
#define BG_GREEN		"\u001b[42m"
#define BG_YELLOW		"\u001b[43m"
#define BG_BLUE			"\u001b[44m"
#define BG_MAGENTA		"\u001b[45m"
#define BG_CYAN			"\u001b[46m"
#define BG_WHITE		"\u001b[47m"

// ANSI escape sequence for setting default console text foreground and background colors
#define RESET_COLORS	"\u001b[0m"

#endif // !ANSI_COLORS_H
