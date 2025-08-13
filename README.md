# minishell

## Overview
minishell is a custom implementation of a Unix shell that provides a command-line interface for executing programs, managing processes, and handling basic shell operations. This project demonstrates process management, signal handling, environment variable management, and command parsing.

## Features
- **Command Execution**: Runs external programs and built-in commands
- **Process Management**: Handles process creation, termination, and control
- **Signal Handling**: Manages keyboard interrupts and process signals
- **Environment Variables**: Supports environment variable expansion and management
- **Command Parsing**: Parses complex command lines with pipes and redirections
- **Built-in Commands**: Implements essential shell commands
- **Pipeline Support**: Handles command chaining with pipes

## Built-in Commands
- `echo` - Display text with optional flags
- `cd` - Change directory
- `pwd` - Print working directory
- `export` - Set environment variables
- `unset` - Remove environment variables
- `env` - Display environment variables
- `exit` - Exit the shell

## How It Works
1. **Command Input**: Reads and parses user input
2. **Tokenization**: Splits input into tokens and handles quotes
3. **Command Parsing**: Identifies commands, arguments, and operators
4. **Process Execution**: Creates child processes for external commands
5. **Signal Management**: Handles interrupts and process control
6. **Environment Management**: Manages shell environment variables

## Project Structure
```
minishell/
├── minishell.h              # Header file with structures and declarations
├── SRCS/                    # Source code directory
│   ├── main.c              # Main program entry point
│   ├── shell.c             # Core shell logic
│   ├── parser.c            # Command parsing functions
│   ├── executor.c          # Command execution logic
│   ├── builtins.c          # Built-in command implementations
│   ├── signals.c           # Signal handling
│   ├── env.c               # Environment variable management
│   └── utils.c             # Utility functions
├── libft/                   # Libft library dependency
├── Makefile                 # Build configuration
└── .git/                   # Git repository
```

## Supported Features
- **Command Execution**: External programs and built-ins
- **Pipes**: Command chaining with `|`
- **Redirections**: Input/output redirection with `<`, `>`, `>>`
- **Environment Variables**: Expansion with `$` syntax
- **Quotes**: Single and double quote handling
- **Signal Handling**: Ctrl+C, Ctrl+D, Ctrl+\
- **Working Directory**: Current directory management

## Usage
```bash
# Compile the shell
make

# Run the shell
./minishell

# Exit the shell
exit

# Clean build files
make clean
```



## Requirements
- GCC compiler
- Make utility
- Standard C libraries
- POSIX system calls
- Libft library (dependency)

## Dependencies
This project depends on the Libft library for basic string and memory functions.

## Shell Features
- **Prompt Display**: Shows current working directory
- **Command History**: Basic command history (if implemented)
- **Tab Completion**: File and command completion (if implemented)
- **Error Handling**: Comprehensive error messages
- **Exit Status**: Proper exit codes for commands

## Process Management
- **Fork and Exec**: Creates child processes for external commands
- **Wait and Exit**: Properly waits for child processes
- **Signal Handling**: Manages process interrupts
- **Background Processes**: Support for background execution (if implemented)

## Notes
- Follows 42 coding style (norminette)
- Implements robust process management
- Handles edge cases and error conditions
- Memory-safe implementation
- Compatible with standard shell behavior

## Author
shmohamm - 42 Abu Dhabi
