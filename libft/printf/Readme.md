*This project has been created as part of the 42 curriculum by ny-handr.*

# Printf

## Description

**ft_printf** is a project that is part of milestone 1 at Ecole 42. The goal is to reimplement the printf function from the standard C library. This custom implementation, named ft_printf, must handle various format specifiers and produce output identical to the original printf. All functions are written in C and follow the strict coding style enforced at 42 (the Norm).

The project focuses on understanding variadic functions, string formatting, and low-level output operations in C.

## Features

The ft_printf function supports the following format specifiers:
- `%c`: Print a single character
- `%s`: Print a string
- `%p`: Print a pointer address in hexadecimal
- `%d` and `%i`: Print a signed integer
- `%u`: Print an unsigned integer
- `%x` and `%X`: Print an unsigned integer in hexadecimal (lowercase/uppercase)
- `%%`: Print a percent sign

## Algorithm and Data Structures

### Algorithm

The implementation uses C's variadic functions feature through the `<stdarg.h>` header. The `va_list` type and macros (`va_start`, `va_arg`, `va_end`) are used to access the variable arguments passed to ft_printf.

The main algorithm in `ft_printf`:
1. Parse the format string character by character.
2. When a '%' is encountered, identify the format specifier.
3. Use the appropriate helper function to convert and print the corresponding argument.
4. For non-format characters, print them directly.

This approach ensures efficient parsing and handling of format strings of arbitrary length.

### Data Structures

No complex data structures are used in this implementation. The function relies on standard C types and the variadic argument list. Helper functions are used to handle different data types, keeping the code modular and readable.

## Instructions

### Usage

1. Clone the repository:

```bash
git clone git@vogsphere.42antananarivo.mg:vogsphere/intra-uuid-49bb7fe7-7af0-4784-bfb5-8a8b272170d8-7270374-ny-handr ft_printf
cd ft_printf
```

2. Build the library:

```bash
make
```

This produces `libftprintf.a`.

3. Include the header and link the library in your own project:

```c
#include "ft_printf.h"
```

```bash
cc -Wall -Wextra -Werror your_file.c -L. -lftprintf -o your_program
```

### Makefile Targets

| Target              | Description                                     |
| ------------------- | ----------------------------------------------- |
| `make` / `make all` | Compiles all source files and creates `libftprintf.a` |
| `make clean`        | Removes object files                            |
| `make fclean`       | Removes object files and `libftprintf.a`        |
| `make re`           | Runs `fclean` then `all`                        |

## Resources

### References
- [Variadic Functions in C - GeeksforGeeks](https://www.geeksforgeeks.org/c/variadic-functions-in-c/): Used to learn about variadic functions, va_list, and related macros.
- [42 Cursus Guide - ft_printf](https://42-cursus.gitbook.io/guide/1-rank-01/ft_printf/variadic-functions): Provided additional insights into implementing variadic functions for the ft_printf project.

### AI Usage
AI (GitHub Copilot) was used to assist in drafting and structuring this README file.
