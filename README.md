# minishell2 ⌨️

Welcome to **minishell2**.

The continuation of your journey in Shell Programming.

This project, as a part of the B2 curriculum, aims to enhance your minishell1 project by introducing additional shell functionalities such as `semicolons`, `pipes`, and `redirections`.

## Language and Tools 🛠️

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

- **Language:** C
- **Compilation:** Via Makefile, including `re`, `clean`, and `fclean` rules.
- **Binary Name:** mysh

## Project Overview 🔎

The goal of `minishell2` is to expand upon the basic shell programming skills acquired in `minishell1`.

This involves adding complex shell features like command separation with semicolons, command piping, and file redirections, bringing you one step closer to implementing a fully functional shell.

### Core Features

- **Command Separation:** Use of semicolons (`;`) to execute multiple commands sequentially.
- **Command Piping:** Implementation of pipes (`|`) to redirect the output of one command to another.
- **File Redirections:** Support for input (`<`), output (`>`), and append (`>>`) redirections.

### Usage Examples

```
∼> ./mysh
> ls -l; ls -l | wc -l
total 4
drwxr-xr-x 2 johan johan 4096 Mar 17 16:28 tata
-rw-r–r– 1 johan johan 0 Mar 17 16:28 toto
3
>

∼> ./mysh
> mkdir test ; cd test ; ls -a ; ls | cat | wc -c > tutu ; cat tutu
. ..
5
>
2
```


## Prerequisites

- Completion of the `minishell1` project is required.

## Authorized Functions

- Memory and Directory Management: `malloc`, `free`, `exit`, `opendir`, `readdir`, `closedir`, `getcwd`, `chdir`
- File and Process Management: `fork`, `stat`, `lstat`, `fstat`, `open`, `close`, `getline`, `strtok`, `strtok_r`
- System Calls and Signal Handling: `read`, `write`, `execve`, `access`, `isatty`, `wait`, `waitpid`, `wait3`, `wait4`, `signal`, `kill`, `getpid`, `strerror`, `perror`, `strsignal`
- Additional: `pipe`, `dup`, `dup2`

## Installation and Usage 💾

1. Clone the repository.
2. Compile the program using the provided Makefile.
3. Run the shell using: `./mysh`.
4. For detailed guidelines, refer to `minishell2.pdf`.

## License ⚖️

This project is released under the MIT License. See `LICENSE` for more details.
