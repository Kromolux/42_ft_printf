# 42_ft_printf

## Description

This project is pretty straightforward, you have to recode printf. You will learn what is and how to implement variadic functions. Once you validate it, you will reuse this function in your future projects.

## Skills

* Rigor
* Algorithms & AI

## Introduction

The versatility of the printf function in C represents a great exercise in programming for
us. This project is of moderate difficulty. It will enable you to discover variadic functions
in C.
The key to a successful ft_printf is a well-structured and good extensible code.

## Mandatory part

Program name libftprintf.a
Turn in files *.c, */*.c, *.h, */*.h, Makefile
Makefile all, clean, fclean, re, bonus
External functs. malloc, free, write, va_start, va_arg, va_copy, va_end
Libft authorized yes
Description Write a library that contains ft_printf, a function that will mimic the real printf

* The prototype of ft_printf should be int ft_printf(const char *, ...);
* You have to recode the libc’s printf function
* It must not do the buffer management like the real printf
* It will manage the following conversions: cspdiuxX%
* It will be compared with the real printf
* You must use the command ar to create your librairy, using the command libtool
is forbidden.
### A small description of the required conversion:
* %c print a single character.
* %s print a string of characters.
* %p The void * pointer argument is printed in hexadecimal.
* %d print a decimal (base 10) number.
* %i print an integer in base 10.
* %u print an unsigned decimal (base 10) number.
* %x print a number in hexadecimal (base 16), with lowercase.
* %X print a number in hexadecimal (base 16), with uppercase.
* %% print a percent sign

## Bonus part

* If the Mandatory part is not perfect don’t even think about bonuses
* You don’t need to do all the bonuses
* Manage any combination of the following flags: ’-0.’ and minimum field width
with all conversions
* Manage all the following flags: ’# +’ (yes, one of them is a space)

