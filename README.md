# Solution to Euler Project

- My [Notes](./NOTES.md) along the way.
- Ref to each problem: [https://projecteuler.net/problem=N]()
- Ref to [numeric answers](https://github.com/nayuki/Project-Euler-solutions/blob/master/Answers.txt)

---

## Build

To build all of the problems:

```sh
mkdir build
make
```

To build a specific target (not that numbers should be zero-prefixed if they are two or one digit numbers)

```sh
# Assuming build/ is created
make 007
make 042
make 123
```

To clean the build simpl


## Chrono

- To time a piece of code

  ```c
  #include "utils/chrono"

  ...

  chrono
  {
      your code here
  }
  ```

  this will print elapsed time to stdout

- To disable chrono without removing the code, define the following symbol
  before `#include "utils/chrono"` atop your code.

  ```c
  #define NOCHRONO
  ```
