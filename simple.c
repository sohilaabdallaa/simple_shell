#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
extern char **environ;
int countWords(char *line) {
    int numWords = 0;
    int inWord = 0;

    while (*line != '\0') {
        if (*line == ' ' || *line == '/' || *line == '\n') {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            numWords++;
        }
        line++;
    }

    return numWords;
}

int main() {

char *buffer = NULL;
char *line = NULL;
char *token = NULL;
char **tokens = NULL;
size_t bufsize = 0;
int nword = 0;
int i = 0;
ssize_t nread = 0;
pid_t childID;
pid_t wpid;
int status;

while(nread >= 0)
{
if (isatty(STDIN_FILENO))
    write(STDOUT_FILENO, "($) ", 4);
nread = getline(&buffer, &bufsize, stdin);
if (nread == -1)
{
    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "\n", 1);
    perror("./hsh");
    break;
}
/* remove the '/n' char from read line not from the buffer*/
i = nread - 1;
line = buffer;
if (buffer[i] == '\n')
    line[i] = '\0';

/*           Create word count function here       */
nword = countWords(line);
/*           Create Tokinazing function here       */
i = 0;
tokens = malloc(sizeof(char*) * (nword + 1));
if (!tokens)
    return (-1);

token = strtok(line, " ");
while (token != NULL)
{
    tokens[i] = token;
   printf("%s\n", tokens[i]);
    token = strtok(NULL, " ");
    i++;
}
/* this null here to be the end of the array so i can use tkoens in execve*/
tokens[i] = NULL;

childID = fork();
if (childID == 0)
{
    execve(tokens[0], tokens,environ);
    perror("./hsh");
    exit(EXIT_FAILURE);
}
else if (childID == -1)
{
    perror("fork");
    return (-1);
}
else
{
    do {
        /*child has stopped but has not been traced.*/
    wpid = waitpid(childID, &status, WUNTRACED);
    if (wpid == -1) {
        perror("waitpid");
        exit(EXIT_FAILURE);
    }
} while (!WIFEXITED(status) && !WIFSIGNALED(status));

}

free(tokens);
line = NULL;
}
return (0);
}
