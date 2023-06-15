# 0x17. C - Doubly linked lists

**General:**
- What is a doubly linked list.
- How to use doubly linked lists.
## Requirements:

 **General:**
 - Allowed editors: `v`i, `vim`, `emacs`.
 - All files will be interpreted/compiled on Ubuntu 20.04 LTS using python3 (version 3.8.5).
 - All files should end with a new line.
 - A `README.md` file, at the root of the folder of the project is mandatory.
 - The code should use the `Betty` style. It will be checked using betty-style.pl and betty-doc.pl.
 - Not allowed to use global variables.
 - No more than 5 functions per file.
 - The only C standard library functions allowed are `malloc`, `free`, `printf` and `exit`.
 - The prototypes of all the functions should be included in a header file called `lists.h`.

## List of files:

**lists.h:**
- A `header` file that defines and implements a doubly linked list of integers in `C`. It has a structure called `dlistint_t` that represents a list node with an integer value and pointers to the previous and next nodes. It also has several functions for `creating`, `printing`, `freeing`, `inserting`, `deleting`, and `manipulating` the list. It can be found at [insert your file path here].

**0-print_dlistint.c:**
  - a function that prints all the elements of a `dlistint_t` list.
    - Prototype: `size_t print_dlistint(const dlistint_t *h);`.
    - Return: the number of nodes.
