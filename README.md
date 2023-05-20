# Simple Shell
![shell](https://github.com/sohilaabdallaa/simple_shell/assets/53753947/a0ffabd4-6333-4bb2-891d-57244541c0ff)

## Description
This is a simple shell program written in C. It provides basic functionality for running and executing commands within a Unix-like environment.

## Features
- Executes commands entered by the user
- Supports command line arguments
- Provides basic error handling

## Installation
1. Clone the repository: `git clone https://github.com/username/simple-shell.git`
2. Build the project: `make`
3. Run the program: `./hsh`

## Compilation
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Testing
Your shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## Usage
1. Launch the shell program by running the `./simple-shell` command.
2. Enter commands at the prompt and press Enter to execute them.

### Examples
Here are some example commands you can enter:
```
ls -l
cd /home/user/Documents
mkdir new-directory
```

## Future Development
- Add support for piping commands
- Improve error handling and messaging

## Authors
- Sohila Abdalla
- Nada Adel
