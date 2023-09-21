# NOTES


## BITWISE Operator Magics

### `number >>= 1`

The `number >>= 1` statement is a shorthand notation for performing a right shift operation on the variable `number` by 1 bit. It is equivalent to dividing `number` by 2 using bitwise operations.

The `>>=` operator is a compound assignment operator in C and C++. It combines the right shift (`>>`) operator with the assignment (`=`) operator. The expression `number >>= 1` is equivalent to `number = number >> 1`.

Here's a breakdown of what happens in the statement `number >>= 1`:

1. The value of `number` is right-shifted by 1 bit.
2. The result of the right shift operation is assigned back to `number`.

In the context of finding the largest prime factor, the `number >>= 1` statement is used inside the first loop to divide the number by 2 repeatedly until it is no longer divisible by 2. It effectively removes all factors of 2 from the number, allowing subsequent iterations to focus on odd factors.


## Partial Initialization of arrays and `struct`s in C[^1]

[^1]: [Initializing char Array with Smaller String Literal (stackoverflow)](https://stackoverflow.com/a/8245309/13041067) and
    [How to initialize only few elements of an array with some values?(stackoverflow)](https://stackoverflow.com/a/38860092/13041067)


```c
  char arr[8] = "abc";
```

is completely equivalent to

```c
char arr[8] = {'a', 'b', 'c', '\0'};
```

ISO C 6.7.8 §21 states that

> If there are fewer initializers in a brace-enclosed list than there are elements or members of an aggregate, or fewer characters in a string literal used to initialize an array of known size than there are elements in the array, the remainder of the aggregate shall be initialized implicitly the same as objects that have static storage duration[^2].

[^2]: It means global variables or those defined static (both file static or function static). These objects are created before the program starts; the startup code contains commands to "zero out" these objects. This means all pointers are null pointers, all numbers are zero and all character arrays have zero bytes, so that `strlen(arr)` returns `0`. This is actually desirable; the reason this is not done for objects with "automatic storage duration" (local variables) is that it would happen _every time_ the code is passed, as opposed to just once for statics.

In plain English this means that all values at the end of your array will be set to 0. So the standard guarantees that your code is equivalent to:

```c
char arr[8] = {'a', 'b', 'c', '\0', 0, 0, 0, 0};
```

Now of course, `'\0'` happens to be value zero as well.

This rule is universal to all arrays and not just to strings. Also, the same applies when initializing a struct but only explicitly setting a few of its members (6.7.8 §18).

This is why you can write code like

```c
char arr[8] = "";
```

In this example, the first element of the array is initialized explicitly to `'\0'`, and the rest of the items implicitly to zero. The compiler translates this to

```c
char arr[8] = {0, 0, 0, 0, 0, 0, 0, 0};
```

Another example:

```c
// Zeroes out a[1] through a[9]
int a[10] = {1};


typedef struct {
  int i;
  int iarr[10];
  char c;
  char carr[10];
} s_t;

s_t s = {.i = 42};
// now
// iarr = {0, ..., 0}
// c = '\0'
// carr = {'\0', ..., '\0'}


int array[12] = {[8] = 3, [0] = 1, [4] = 2};  // Order in which elements are listed doesn't matter.
// is equivalent to:
int array[12] = {1, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 0};
// note that the expression inside [ ] shall be an integer constant expression.
```
