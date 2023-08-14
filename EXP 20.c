#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Grammar rules
const char *rules[] = {
    "E -> E + T",
    "E -> T",
    "T -> T * F",
    "T -> F",
    "F -> ( E )",
    "F -> id"
};

// Function to find if a string is derivable ambiguously
bool isAmbiguous(const char *input, int start, int end, const char *rule) {
    if (start > end) {
        for (int i = 0; i < 6; i++) {
            if (strcmp(rule, rules[i]) == 0) {
                return true;
            }
        }
        return false;
    }

    for (int i = start; i <= end; i++) {
        if (input[i] == '+' || input[i] == '*') {
            bool left = isAmbiguous(input, start, i - 1, rule);
            bool right = isAmbiguous(input, i + 1, end, rule);
            if (left && right) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    const char *input = "id+id*id";
    int length = strlen(input);

    bool is_ambiguous = false;

    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            if (isAmbiguous(input, i, j, "E -> E + T")) {
                is_ambiguous = true;
                break;
            }
            if (isAmbiguous(input, i, j, "T -> T * F")) {
                is_ambiguous = true;
                break;
            }
        }
        if (is_ambiguous) {
            break;
        }
    }

    if (is_ambiguous) {
        printf("The input string is ambiguous.\n");
    } else {
        printf("The input string is not ambiguous.\n");
    }

    return 0;
}
