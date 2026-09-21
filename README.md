# cvector

A small C dynamic array library for storing homogeneous values in a contiguous block of memory.

This project provides a `t_vector` container similar in spirit to C++ `std::vector`, but implemented using raw byte storage and manual pointer arithmetic. It is designed for lightweight usage in C programs where you want automatic growth, indexed access, and convenience functions without depending on a larger STL or runtime.

## Features

- Dynamic capacity growth and shrink support
- Generic storage via `element_size`
- Indexed access and pointer-based element retrieval
- `push_back`, `push_front`, `insert`, `assign`, `erase`, and `resize`
- Optional destructor callback for element cleanup
- Static library build via `make`

## Project structure

- `inc/vector.h` — public API
- `inc/vector_int.h` — internal constants and private helpers
- `src/` — implementation files

## Build

From the repository root:

```bash
make
```

This produces the static library:

```bash
cvector.a
```

To clean generated artifacts:

```bash
make clean
make fclean
```

## Usage

Include the public header:

```c
#include "vector.h"
```

Then initialize a vector:

```c
#include <stdio.h>
#include "vector.h"

int main(void)
{
    t_vector numbers;
    int a = 10;
    int b = 20;
    int c = 30;

    if (vctrnew(&numbers, 4, sizeof(int), NULL) == ERROR)
        return 1;

    vctrpush_back(&numbers, &a);
    vctrpush_back(&numbers, &b);
    vctrpush_back(&numbers, &c);

    printf("size=%zu capacity=%zu\n",
           vctrsize(&numbers),
           vctrcpcty(&numbers));

    printf("first=%d last=%d\n",
           *(int *)vctrat(&numbers, 0),
           *(int *)vctrat(&numbers, vctrsize(&numbers) - 1));

    vctrrm(&numbers);
    return 0;
}
```

Compile it with the library like this:

```bash
cc main.c -I inc cvector.a -o main
```

## Main API

The library exposes the following core operations:

- `vctrnew` — initialize a vector
- `vctrdup` / `vctrcpy` — duplicate or copy vectors
- `vctrrm` — destroy a vector and free its backing storage
- `vctrpush_back` / `vctrpush_front` / `vctrinsert` — insert elements
- `vctrassign` — replace an element at a given index
- `vctrat`, `vctrfrnt`, `vctrbck`, `vctrdata` — access elements
- `vctrerase`, `vctrpop_back`, `vctrpop_front`, `vctrclear` — remove elements
- `vctrrsrv`, `vctrshrnk`, `vctrresize` — manage capacity and size
- `vctrsize`, `vctrcpcty`, `vctrmxsize`, `vctrmpty` — inspect state
- `vctrprint` — print contents with a custom callback

## Error handling

The library uses the constants:

```c
#define SUCCESS 0
#define ERROR -1
```

Most public functions return `SUCCESS` on success and `ERROR` on failure.

## Notes

- The vector stores raw bytes, so the caller is responsible for correctly passing the right `element_size` and element type.
- If you provide a destructor function in `vctrnew`, it will be used when elements are removed or the vector is destroyed allowing .
- This is a lightweight educational/static library, not a full generic container framework.
