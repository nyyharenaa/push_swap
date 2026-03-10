_This project has been created as part of the 42 curriculum by ny-handr._

# libft

## Description

**libft** is the very first project of the 42 curriculum. The goal is to recode a set of standard C library functions from scratch, building a solid personal library that can be reused throughout the cursus. All functions are written in C and follow the strict coding style enforced at 42 (the Norm).

---

### Functions

#### Libc Functions

Re-implementations of standard C library functions:

| Function     | Description                                        |
| ------------ | -------------------------------------------------- |
| `ft_isalpha` | Checks if a character is alphabetic                |
| `ft_isdigit` | Checks if a character is a digit (0–9)             |
| `ft_isalnum` | Checks if a character is alphanumeric              |
| `ft_isascii` | Checks if a character belongs to the ASCII table   |
| `ft_isprint` | Checks if a character is printable                 |
| `ft_strlen`  | Returns the length of a string                     |
| `ft_memset`  | Fills a memory area with a constant byte           |
| `ft_bzero`   | Sets a byte string to zero                         |
| `ft_memcpy`  | Copies a memory area                               |
| `ft_memmove` | Copies a memory area, handling overlaps            |
| `ft_strlcpy` | Copies a string into a sized buffer                |
| `ft_strlcat` | Appends a string to a sized buffer                 |
| `ft_toupper` | Converts a character to uppercase                  |
| `ft_tolower` | Converts a character to lowercase                  |
| `ft_strchr`  | Locates a character in a string (first occurrence) |
| `ft_strrchr` | Locates a character in a string (last occurrence)  |
| `ft_strncmp` | Compares two strings up to n characters            |
| `ft_memchr`  | Scans memory for a character                       |
| `ft_memcmp`  | Compares two memory areas                          |
| `ft_strnstr` | Locates a substring in a string, bounded by length |
| `ft_atoi`    | Converts a string to an integer                    |
| `ft_calloc`  | Allocates memory and initializes it to zero        |
| `ft_strdup`  | Duplicates a string using malloc                   |

#### Additional Functions

Functions that are not in the standard library but are useful in many programs:

| Function        | Description                                                                       |
| --------------- | --------------------------------------------------------------------------------- |
| `ft_substr`     | Extracts a substring from a string                                                |
| `ft_strjoin`    | Concatenates two strings into a new one                                           |
| `ft_strtrim`    | Trims leading and trailing characters from a string                               |
| `ft_split`      | Splits a string by a delimiter character into an array                            |
| `ft_itoa`       | Converts an integer to a string                                                   |
| `ft_strmapi`    | Applies a function to each character of a string (with index), returns new string |
| `ft_striteri`   | Applies a function to each character of a string (with index), in place           |
| `ft_putchar_fd` | Outputs a character to a file descriptor                                          |
| `ft_putstr_fd`  | Outputs a string to a file descriptor                                             |
| `ft_putendl_fd` | Outputs a string followed by a newline to a file descriptor                       |
| `ft_putnbr_fd`  | Outputs an integer to a file descriptor                                           |

#### Linked List Functions

Functions for manipulating singly linked lists (`t_list`):

| Function          | Description                                                             |
| ----------------- | ----------------------------------------------------------------------- |
| `ft_lstnew`       | Creates a new list node                                                 |
| `ft_lstadd_front` | Adds a node at the beginning of a list                                  |
| `ft_lstsize`      | Returns the number of nodes in a list                                   |
| `ft_lstlast`      | Returns the last node of a list                                         |
| `ft_lstadd_back`  | Adds a node at the end of a list                                        |
| `ft_lstdelone`    | Deletes a node using a given function                                   |
| `ft_lstclear`     | Deletes and frees all nodes of a list                                   |
| `ft_lstiter`      | Applies a function to each node of a list                               |
| `ft_lstmap`       | Applies a function to each node and creates a new list from the results |

---

## Instructions

### Usage

1. Clone the repository:

```bash
git clone git@vogsphere.42antananarivo.mg:vogsphere/intra-uuid-fc1fbfb4-a252-4be1-811a-d53dff089401-7269964-ny-handr libft
cd libft
```

2. Build the library:

```bash
make
```

This produces `libft.a`.

3. Include the header and link the library in your own project:

```c
#include "libft.h"
```

```bash
cc -Wall -Wextra -Werror your_file.c -L. -lft -o your_program
```

---

### Makefile Targets

| Target              | Description                                     |
| ------------------- | ----------------------------------------------- |
| `make` / `make all` | Compiles all source files and creates `libft.a` |
| `make clean`        | Removes object files                            |
| `make fclean`       | Removes object files and `libft.a`              |
| `make re`           | Runs `fclean` then `all`                        |

---

## Resources

### Documentation

- **Ubuntu manual pages (man)** — used as the main reference for understanding the expected behavior of each standard C function (e.g., `man strlen`, `man memcpy`, etc.).

### Articles

- **[W3Schools — C Structures](https://www.w3schools.com/c/c_structs.php)** — consulted to learn and understand the use of structures (`struct`) in C, particularly for the bonus section (linked lists).

### Tutorials

- **YouTube** — watched tutorials on the fundamentals of linked lists (creating nodes, adding, deleting, traversing), used to better understand the `ft_lst*` functions.

---

## Use of AI

Artificial intelligence was used in this project mainly to **test the implemented functions**: generating test cases, checking boundary behaviors, and validating the results obtained.

---

## Author

**ny-handr** — student at 42 Antananarivo
