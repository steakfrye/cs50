# Questions

## What's `stdint.h`?

A header file with typedef structures and functions.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

They represent different unsigned values. You can use them to hold values at their respective bits. They are equal respectively to a BYTE, DWORD, LONG, and WORD.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1, 4, 4, 2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

0x4D42

## What's the difference between `bfSize` and `biSize`?

bfSize is the size of the entire file including the header while biSize is the size of just the header.

## What does it mean if `biHeight` is negative?

The image will be read starting from the upper left corner going down.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

It's a failsafe in case the program tries to open and manipulate something it shouldn't.

## Why is the third argument to `fread` always `1` in our code?

It's reading just the one element.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

It points to a specified byte within a file.

## What is `SEEK_CUR`?

The current position of the file pointer.
