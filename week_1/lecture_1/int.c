// stdio.h - библиотека, корорая выводит printf
# include <stdio.h> 
// The cs50.h file is not the library. It is the “definitions” file.
// you need to have “-lcs50” in your command line to link against the library.  with -l for “link”.
# include <cs50.h>

int main(void)
{
  int i = get_int("Integer: \n");
  printf("Hello, %i\n", i);
  // %i - это плейсхолдер, куда я вставляю вторую переменную функции
}

// to compile:
// $ make int

// to run:
// $ ./int


// VAR2:

// to compile:
// $ clang -o int -lcs50 int.c
// or:
// $ gcc -o int -lcs50 int.c

// where:
// -o int - output's name

// to run:
// $ ./a.out
// or:
// ./int

// C/C++ Compile Run

// f6	Compiles and runs the file
// f8	Compiles and run the file in external console