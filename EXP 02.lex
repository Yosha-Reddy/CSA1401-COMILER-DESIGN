InputSourceProgram:(sample.c)
#define PI 3.14
#include<stdio.h>
#include<conio.h>
voidmain()
{
inta,b,c=30;
printf("hello");
}
Program: (count_macro.l)
%{
int nmacro, nheader;
%}
%%
^#define { nmacro++; }
^#include { nheader++; }
.|\n {  }
%%
int yywrap(void) {
return 1;
}
int main(int argc, char *argv[]) {
yyin = fopen(argv[1], "r");
yylex();
printf("Number of macros defined = %d\n", nmacro);
printf("Number of header files included = %d\n", nheader);
fclose(yyin);
}
