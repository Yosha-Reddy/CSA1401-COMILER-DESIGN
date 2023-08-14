% {
  int counter = 0; %
}
  
%
% [a - zA - Z] + {
  if (yyleng > counter) {
    counter = yyleng;
  }
} %
%
  
main() {
  yylex();
  printf("largest: %d", counter);
  printf("\n");
}
