#ifndef MAIN_H
#define MAIN_H

#include <ctype.h>
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>
/* environment variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);
extern int errno;
/* handle built-ins */
int check_builtin_commands(char **c, char *buf, int lineNumber);
void display_command_prompt(void);
void handle_interrupt_signal(int m);
char **tokenize_user_input(char *lline);
char *test_path(char **patth, char *commd);
char *append_to_path_string(char *patth, char *commd);
int handle_builtin_command(char **commd, char *lline);
void execute_exit_command(char **commd, char *lline);

void print_environment_variables(void);

/* string handlers */
int _strcmp(char *stringone, char *stringtwo);
int _strlen(char *string);
int _strncmp(char *stringone, char *stringtwo, int n);
char *_strdup(char *string);
char *_strchr(char *string, char chara);

void execution(char *conpath, char **arra, int lineNumber);
char *find_path(void);
bool checkspace(char *line);

/* helper function for efficient memory deallocation */
void free_memory_buffers(char **buf);
int mysh_exit(void);

/**
 * struct shel_built - struct to hold the build-in commands
 *
 * @environment_command: the string for the 'env' commant
 * @exit_shell_command: the string for the 'exit' commant
 */
struct shel_built
{
	char *environment_command;
	char *exit_shell_command;
} shel_built;
/**
 * struct shell_info - struct to hold informantion about shell
 *
 * @final_exit_status: the exit status of the last executed command
 * @line_count: the number of lines that have been executed
 */
struct shell_info
{
	int final_exit_status;
	int line_count;
} shell_info;

/**
 *struct shell_flags - struct to hold flags for the shell
 *
 *@is_interactive_shell: true if the shell interactive
 */
struct shell_flags
{
	bool is_interactive_shell;
} shell_flags;


#endif /* MAIN_H */

