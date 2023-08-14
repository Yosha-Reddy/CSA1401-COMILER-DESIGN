#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Non-terminal symbols
#define E 0
#define T 1
#define F 2

// Terminal symbols
#define PLUS 0
#define TIMES 1
#define ID 2
#define LPAREN 3
#define RPAREN 4
#define END 5

// Predictive parsing table
int table[3][6] = {
    {1, -1, -1, 1, -1, -1}, // E
    {2, 3, -1, 2, -1, -1},  // T
    {4, -1, -1, 5, -1, -1}  // F
};

// Stack and input strings
char stack[100];
char input[100];
int top = -1;
int input_index = 0;

void push(char symbol) {
    stack[++top] = symbol;
}

char pop() {
    return stack[top--];
}

int getToken(char c) {
    switch (c) {
        case '+':
            return PLUS;
        case '*':
            return TIMES;
        case 'i':
            return ID;
        case '(':
            return LPAREN;
        case ')':
            return RPAREN;
        case '$':
            return END;
        default:
            return -1;
    }
}

bool predictiveParse() {
    push(END);
    push(E);

    char symbol = input[input_index++];
    while (top != -1) {
        char stack_top = pop();

        if (stack_top == symbol) {
            if (symbol == END) {
                printf("Parsing successful!\n");
                return true;
            }
            symbol = input[input_index++];
        } else {
            int row = stack_top - 'E';
            int col = getToken(symbol);

            if (row < 0 || row >= 3 || col < 0 || col >= 6) {
                printf("Error: Invalid input symbol or parsing table entry.\n");
                return false;
            }

            int production = table[row][col];
            if (production == -1) {
                printf("Error: No production rule found.\n");
                return false;
            }

            switch (production) {
                case 1:
                    push('T');
                    push('+');
                    push('E');
                    break;
                case 2:
                    push('F');
                    push('*');
                    push('T');
                    break;
                case 3:
                    push('F');
                    break;
                case 4:
                    push(')');
                    push('E');
                    push('(');
                    break;
                case 5:
                    break;
                default:
                    printf("Error: Invalid production.\n");
                    return false;
            }
        }
    }

    return false;
}

int main() {
    printf("Enter an input string: ");
    scanf("%s", input);

    if (predictiveParse()) {
        printf("Input string is valid.\n");
    } else {
        printf("Input string is invalid.\n");
    }

    return 0;
}
