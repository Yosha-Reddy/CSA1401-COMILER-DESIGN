#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// SLR parsing table
int actionTable[8][6] = {
    {5, 0, 0, 4, 0, 0},
    {0, 6, 0, 0, 0, -1},
    {0, -3, 7, 0, -3, -3},
    {0, -6, -6, 0, -6, -6},
    {5, 0, 0, 4, 0, 0},
    {0, -8, -8, 0, -8, -8},
    {5, 0, 0, 4, 0, 0},
    {5, 0, 0, 4, 0, 0}
};

int gotoTable[8][3] = {
    {1, 2, 3},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {8, 2, 3},
    {0, 0, 0},
    {0, 9, 3},
    {0, 0, 10}
};

char input[100];
int stack[100];
int top = -1;
int input_index = 0;

void push(int state) {
    stack[++top] = state;
}

int pop() {
    return stack[top--];
}

int getToken(char c) {
    switch (c) {
        case '+':
            return 0;
        case '*':
            return 1;
        case '(':
            return 2;
        case ')':
            return 3;
        case 'id':
            return 4;
        case '$':
            return 5;
        default:
            return -1;
    }
}

bool parseSLR() {
    push(0);
    char symbol = input[input_index++];

    while (true) {
        int state = stack[top];
        int token = getToken(symbol);

        int action = actionTable[state][token];

        if (action == 0) {
            printf("Error: Invalid action.\n");
            return false;
        } else if (action > 0) {
            push(action);
            symbol = input[input_index++];
        } else {
            int reduceProduction = -action;
            int lhs = reduceProduction;
            int rhsLength = 2;

            if (lhs == 1) {
                rhsLength = 1;
            }

            for (int i = 0; i < rhsLength; i++) {
                pop();
            }

            int newState = gotoTable[stack[top]][lhs - 1];
            push(newState);

            if (reduceProduction == 3) {
                printf("Reduced: F -> ( E )\n");
            } else if (reduceProduction == 6) {
                printf("Reduced: T -> T * F\n");
            } else if (reduceProduction == 7) {
                printf("Reduced: T -> F\n");
            } else if (reduceProduction == 8) {
                printf("Reduced: E -> E + T\n");
            } else if (reduceProduction == 9) {
                printf("Reduced: E -> T\n");
            } else if (reduceProduction == 10) {
                printf("Parsing successful!\n");
                return true;
            }
        }
    }

    return false;
}

int main() {
    printf("Enter an input string: ");
    scanf("%s", input);

    if (parseSLR()) {
        printf("Input string is valid.\n");
    } else {
        printf("Input string is invalid.\n");
    }

    return 0;
}
