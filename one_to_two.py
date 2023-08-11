#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    int errnum[1];
    char *cmd;
    char **options;
    char *hshname;
    int exit_Num[1];
} shellDType;

void printCmt(int num) {
    // Your printCmt implementation here
}

void freSingle(char *str) {
    // Your freSingle implementation here
}

char* intToAlph(int num) {
    // Your intToAlph implementation here
}

char* stringConcatFunc(const char *str1, const char *str2) {
    // Your stringConcatFunc implementation here
}

void concatErrorMessage(char **concat_b, const char *sh_Name, const char *collctspace, int cnter, int errNum, char *err[], char **optNoni) {
    *concat_b = stringConcatFunc(sh_Name, collctspace);
    if (!*concat_b) {
        printCmt(1);
        return;
    }

    if (errNum == 7) {
        char *concat_a = "fol";
        errorStrFunc_inner(errNum, *concat_b, concat_a, err, 0);
    }

    char *numStr = intToAlph(cnter);
    if (!numStr) {
        printCmt(1);
        freSingle(*concat_b);
        return;
    }

    char *concat_a = stringConcatFunc(*concat_b, numStr);
    freSingle(*concat_b);
    freSingle(numStr);

    if (!concat_a) {
        printCmt(1);
        return;
    }

    *concat_b = stringConcatFunc(concat_a, collctspace);
    freSingle(concat_a);

    if (!*concat_b) {
        printCmt(1);
        return;
    }

    *concat_b = stringConcatFunc(*concat_b, err[errNum]);
    if (!*concat_b) {
        printCmt(1);
        return;
    }

    if (errNum > 1 && errNum < 6 && errNum != 3) {
        *concat_b = errorStrFunc2(errNum, *concat_b, optNoni[1]);
        /* *concat_b = errorStrFunc2(errNum, *concat_b, optNoni); */
        if (*concat_b == NULL) {
            printCmt(1);
            return;
        }
    }
}

int errorStrFunc(int errNum, shellDType *shellVar, int exnum) {
    int cnter = shellVar->errnum[0], z = 0;
    char *cmd = shellVar->cmd, **optNoni = shellVar->options;
    char *sh_Name = shellVar->hshname;
    char *collctspace = ": ";
    char *err[] = {
        "not found", "Permission denied", "Illegal number",
        "name is NULL, points to string of len 0, or has an '=' char.",
        "can't cd to ", "Illegal optNoni ", "Help command error",
        "Error allocating memory", "Wrong Alias",
        NULL
    };

    char *concat_b = NULL;
    concatErrorMessage(&concat_b, sh_Name, collctspace, cnter, errNum, err, optNoni);

    if (!concat_b) {
        return -1;
    }

    while (concat_b[z] != 0) {
        z++;
    }

    write(2, concat_b, z);
    printCmt(2);
    freSingle(concat_b);
    shellVar->exit_Num[0] = exnum;
    return 0;
}

