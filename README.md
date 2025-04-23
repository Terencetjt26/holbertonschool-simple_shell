# Simple Shell - Holberton School Project

![Version](https://img.shields.io/badge/version-1.0.0-blue.svg)
![Linux](https://img.shields.io/badge/linux-ubuntu-orange.svg)
![MacOS](https://img.shields.io/badge/macos-monterey-lightgrey.svg)
![C](https://img.shields.io/badge/language-C-red.svg)


#

### Table of Contents
<details>
<summary>Click to expand</summary>

- [Description](#description)
- [Version](#version)
- [Files](#files)
- [Built-in Commands](#built-in-commands)
- [Manual Pages](#manual-pages)
- [Installation](#installation)
- [Usage](#usage)
- [Authors &copy;](#authors--copy)

</details>

#### Description
Simple Shell is a simple UNIX command interpreter written in C. It is designed to mimic the behavior of the original Bourne shell `(sh)` and provides a basic command-line interface for users to execute commands and manage processes.

#### Version
- `1.0.0` - Initial release - 2025-04-23

#

#### Files
| File | Description | Link |
| ---- | ----------- | ---- |
| `shell.h` | Header file containing function prototypes and structure definitions. | [View](shell.h) |
| `shell.c` | Main shell program that handles user input and command execution. | [View](shell.c) |
| `execute_command.c` | Functions for executing commands and managing processes. | [View](execute_command.c) |
| `tokenize.c` | Tokenization of user input into command and arguments. | [View](tokenize.c) |
| `environement.c` | Functions for managing environment variables. | [View](environment.c) |
| `builtins.c` | Implementation of built-in shell commands (cd, exit, env). | [View](builtins.c) |
| `utils.c` | Utility functions for string manipulation and error handling. | [View](utils.c) |
| `path.c` | Functions for searching and executing commands in the system PATH. | [View](path.c) |

#### Built-in Commands
| Command | Description |
| ------- | ----------- |
| `cd` | Change the current directory. |
| `exit` | Exit the shell. |
| `env` | Display the current environment variables. |

#### Manual Pages
```bash
$ man ./man_1_simple_shell
```

#### Installation
To install and run the Simple Shell, follow these steps:
1. Clone the repository:
```bash
$ git clone https://github.com/Terencetjt26/holbertonschool-simple_shell.git
$ cd holbertonschool-simple_shell
```

2. Compile the source code:
```bash
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
3. Run the shell:
```bash
$ ./hsh
```

#### Usage
> The shell can be used interactively or in a non-interactive mode. In interactive mode, it will prompt the user for input and execute commands. In non-interactive mode, it can read commands from a file or standard input.
##### Example
```bash
$ ./hsh
root@cisfun:/home/ubuntu/holbertonschool-simple_shell$ ls
AUTHORS  README.md  builtins.c  environement.c  execute_command.c  hsh  man_1_simple_shell  path.c  shell.c  shell.h  tokenize.c  utils.c
root@cisfun:/home/ubuntu/holbertonschool-simple_shell$ pwd
/home/ubuntu/holbertonschool-simple_shell
root@cisfun:/home/ubuntu/holbertonschool-simple_shell$ echo hello-world
hello-world
root@cisfun:/home/ubuntu/holbertonschool-simple_shell$ exit
$
```

In the non-interactive mode, you can run the shell with input redirection:
```bash
$ echo "ls -l" | ./hsh
total 64
-rw-r--r-- 1 root root   141 Apr 23 15:03 AUTHORS
-rw-r--r-- 1 root root  3414 Apr 23 15:30 README.md
-rw-r--r-- 1 root root  1396 Apr 23 15:03 builtins.c
-rw-r--r-- 1 root root   655 Apr 23 15:03 environement.c
-rw-r--r-- 1 root root   453 Apr 23 15:03 execute_command.c
-rwxr-xr-x 1 root root 17592 Apr 23 15:07 hsh
-rw-r--r-- 1 root root     2 Apr 23 15:03 man_1_simple_shell
-rwxr-xr-x 1 root root   684 Apr 23 15:03 path.c
-rwxr-xr-x 1 root root  1398 Apr 23 15:03 shell.c
-rwxr-xr-x 1 root root  1320 Apr 23 15:03 shell.h
-rw-r--r-- 1 root root   528 Apr 23 15:03 tokenize.c
-rwxr-xr-x 1 root root  1076 Apr 23 15:03 utils.c
$
```

#### Authors &copy;
- **Martin Clement** - [Github Profile](https://github.com/ItsZmainDev)
- **Terence Tengue** - [Github Profile](https://github.com/Terencetjt26)