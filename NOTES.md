# NOTES


## BITWISE Operator Magics

### `number >>= 1`

The `number >>= 1` statement is a shorthand notation for performing a right shift operation on the variable `number` by 1 bit. It is equivalent to dividing `number` by 2 using bitwise operations.

The `>>=` operator is a compound assignment operator in C and C++. It combines the right shift (`>>`) operator with the assignment (`=`) operator. The expression `number >>= 1` is equivalent to `number = number >> 1`.

Here's a breakdown of what happens in the statement `number >>= 1`:

1. The value of `number` is right-shifted by 1 bit.
2. The result of the right shift operation is assigned back to `number`.

In the context of finding the largest prime factor, the `number >>= 1` statement is used inside the first loop to divide the number by 2 repeatedly until it is no longer divisible by 2. It effectively removes all factors of 2 from the number, allowing subsequent iterations to focus on odd factors.
