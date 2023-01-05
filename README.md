# 42_ft_printf

## Description
This project is pretty straightforward, you have to recode printf. You will learn what is and how to implement variadic functions. Once you validate it, you will reuse this function in your future projects.

## Keywords
* Unix logic

## Skills
* Rigor
* Algorithms & AI


# printf
Because putnbr and putstr aren’t enough

Summary: This project is pretty straight forward. You will recode printf. Fortunetaly
you will be able to reuse it in future projects as a legit function of your libft. You will
mainly learn how to use variadic arguments.

Version: 9

## Common Instructions
* Your project must be written in accordance with the Norm. If you have bonus files/functions, they are included in the norm check and you will receive a 0 if there is a norm error inside.
* Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors. If this happens, your project will be considered non functional and will receive a 0 during the evaluation.
* All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated.
* If the subject requires it, you must submit a Makefile which will compile your source files to the required output with the flags -Wall, -Wextra and -Werror, use cc, and your Makefile must not relink.
* Your Makefile must at least contain the rules $(NAME), all, clean, fclean and re.
* To turn in bonuses to your project, you must include a rule bonus to your Makefile, which will add all the various headers, librairies or functions that are forbidden on the main part of the project. Bonuses must be in a different file _bonus.{c/h}. Mandatory and bonus part evaluation is done separately.
* If your project allows you to use your libft, you must copy its sources and its associated Makefile in a libft folder with its associated Makefile. Your project’s Makefile must compile the library by using its Makefile, then compile the project.
* We encourage you to create test programs for your project even though this work won’t have to be submitted and won’t be graded. It will give you a chance to easily test your work and your peers’ work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.
* Submit your work to your assigned git repository. Only the work in the git repository will be graded. If Deepthought is assigned to grade your work, it will be done after your peer-evaluations. If an error happens in any section of your work during Deepthought’s grading, the evaluation will stop.


## Mandatory part
| | |
 :--- | :--- 
Program name | libftprintf.a
Turn in files | *.c, */*.c, *.h, */*.h, Makefile
Makefile | all, clean, fclean, re, bonus
External functs. | malloc, free, write, va_start, va_arg, va_copy, va_end
Libft authorized | yes
Description | Write a library that contains ft_printf, a function that will mimic the real printf

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

> for more complete references : man 3 printf / man 3 stdarg

## Bonus part

* If the Mandatory part is not perfect don’t even think about bonuses
* You don’t need to do all the bonuses
* Manage any combination of the following flags: ’-0.’ and minimum field width
with all conversions
* Manage all the following flags: ’# +’ (yes, one of them is a space)

> If you plan to do bonuses you should think about how to do them from
the beginning to avoid a naive approach.
