# 0x1A. C - Hash tables

### Requirements
**General**
  - Allowed editors: `vi`, `vim`, `emacs`
  - All the files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
  - All the files should end with a new line
  - A `README.md` file, at the root of the folder of the project is mandatory
  - The code should use the Betty style. It will be checked using `betty-style.pl` and `betty-doc.pl`
  - Not allowed to use global variables
  - No more than 5 functions per file
  - Allowed to use the C standard library
  - The prototypes of all the functions should be included in a header file called `hash_tables.h`

**Data Structures:**
```
/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
     char *key;
     char *value;
     struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
     unsigned long int size;
     hash_node_t **array;
} hash_table_t;
```
```
/**
 * struct shash_node_s - Node of a sorted hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 * @sprev: A pointer to the previous element of the sorted linked list
 * @snext: A pointer to the next element of the sorted linked list
 */
typedef struct shash_node_s
{
     char *key;
     char *value;
     struct shash_node_s *next;
     struct shash_node_s *sprev;
     struct shash_node_s *snext;
} shash_node_t;

/**
 * struct shash_table_s - Sorted hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 * @shead: A pointer to the first element of the sorted linked list
 * @stail: A pointer to the last element of the sorted linked list
 */
typedef struct shash_table_s
{
     unsigned long int size;
     shash_node_t **array;
     shash_node_t *shead;
     shash_node_t *stail;
} shash_table_t;
```

### List of the files:
- **hash_tables.h:**
   - The header file contains the prototypes of all the functions and data structures.
- **0-hash_table_create.c:**
   - Prototype: `hash_table_t *hash_table_create(unsigned long int size);`
   - A function that creates a hash table.
     - where size is the `size` of the array
   - Returns a pointer to the newly created hash table.
- **1-djb2.c:**
  - Prototype: `unsigned long int hash_djb2(const unsigned char *str);`
  - a hash function implementing the djb2 algorithm.
  - This algorithm uses a combination of **shift**, **add** and **xor** operations to generate a hash value from a string. It was first reported by **Dan Bernstein** many years ago in comp.lang.c1. The magic of number **33** (why it works better than many other constants, prime or not) has never been adequately explained2.
- **2-key_index.c:**
  - Prototype: `unsigned long int key_index(const unsigned char *key, unsigned long int size);`
  - A function that gives you the index of a key.
  - This function uses the **modulo** operation to map the hash value to an index within the array of the hash table. This ensures that the index is always between **0** and **size - 1**.
- **3-hash_table_set.c:**
  - Prototype: `int hash_table_set(hash_table_t *ht, const char *key, const char *value);`
  - A function that adds an element to the hash table.
  - This function uses the **hash_table_create, hash_djb2** and **key_index** functions that you wrote earlier. It also uses **string.h** library functions to compare and duplicate strings. It handles collisions by adding the new node at the beginning of the linked list at the corresponding index. It also checks for memory allocation errors and returns accordingly.
- **4-hash_table_get.c:**
  - Prototype: `char *hash_table_get(const hash_table_t *ht, const char *key);`
  - A function that retrieves a value associated with a key.
  - This function uses the **key_index** function. It also uses **string.h** library function to compare strings. It returns the value associated with the key if it exists in the hash table, or NULL otherwise.
- **5-hash_table_print.c:**
  - Prototype: `void hash_table_print(const hash_table_t *ht);`
    - where `ht` is the hash table
  - A function that prints a hash table.
  - This function uses **stdio.h** library function to print the hash table. It prints the key/value pairs in the order that they appear in the array of hash table, separated by commas and spaces, and enclosed in curly braces. It also handles the case when ht is NULL or empty.
- **6-hash_table_delete.c**
  - Prototype: `void hash_table_delete(hash_table_t *ht);`
    - where `ht` is the hash table
  - a function that deletes a hash table.
  - This function uses **stdlib.h** library function to free the memory allocated for the hash table. It frees the key and value strings, the nodes, the array and the hash table struct. It also handles the case when ht is NULL.
- **100-sorted_hash_table.c:**
  
   ![what](http://www.smartinsights.com/wp-content/uploads/2017/09/email-marketing-testing-shocked.gif)
  - Prototypes:
      - `shash_table_t *shash_table_create(unsigned long int size);`
      - `int shash_table_set(shash_table_t *ht, const char *key, const char *value);`
      - `char *shash_table_get(const shash_table_t *ht, const char *key);`
      - `void shash_table_print(const shash_table_t *ht);`
      - `void shash_table_print_rev(const shash_table_t *ht);`
      - `void shash_table_delete(shash_table_t *ht);`
  - The key/value pair should be inserted in the sorted list at the right place.
  - Note that here we do not want to do exactly like **PHP**: we want to create a sorted linked list, by key.sorted on ASCII value), that we can print by traversing it
  - Should print the hash table using the sorted linked list.
  - Should print the hash tables key/value pairs in reverse order using the sorted linked list.
   ![php](https://www.alwaysdata.com/static/img/technologies/languages/php.png)
