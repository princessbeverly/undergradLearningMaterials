/*

CSC 112 - BNO1

ALA-AN, PRINCESS BEVERLY
ALIÑGASA, EARL JAMES WILLIAMS

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_TOK_PER_INSTR	64	/* Max tokens per instruction */
#define MAX_TOK_LEN			16	/* Max token length (in char) */

/**
 * These are used as return values for getInstrTypes().
 */
enum InstrTypes {
	BAD_SYNTAX,
	GOOD_SYNTAX
};

/**
 * These are used as return values for getTokTypes().
 */
enum TokTypes {
	INT_TYPE,
	INT_VALUE,
	VARIABLE,
	ASSIGNER,
	OPERATOR,
	TERMINAL
};

/**
 * Parses a line of instruction (assuming two statements are not in one line).
 *
 * Returns the number of tokens found.
 */
int parseInstr(char toks[MAX_TOK_PER_INSTR][MAX_TOK_LEN], char instr[]) {
	int tokCount = 0;
	int tokLen = 0;
	int i = 0;

	/* The instruction line needs to be read until the end of the string. */
	while (instr[i] != '\0' && instr[i] != '\n') {
		char temp = instr[i];

		switch (temp) {

			/* Tokens are split around spaces. */
			case ' ':
				if (tokLen == 0) {
					break;
				}

				toks[tokCount][tokLen] = '\0';
				tokLen = 0;
				tokCount ++;
				break;

			/* Tokens are split around operators, terminals, and assigners. */
			case '=': case '+': case ';':
				if (tokLen > 0) {
					toks[tokCount][tokLen] = '\0';
					tokLen = 0;
					tokCount ++;
				}

				toks[tokCount][tokLen] = temp;
				tokLen ++;
				toks[tokCount][tokLen] = '\0';
				tokLen = 0;
				tokCount ++;
				break;

			/* If the above did not occur, then characters are added to the token. */
			default:
				toks[tokCount][tokLen] = temp;
				tokLen ++;

		}

		i ++;
	}

	return tokCount;
}

/**
 * Gets the type for each token in `toks` and updates `tokTypes`.
 */
void getTokTypes(char toks[MAX_TOK_PER_INSTR][MAX_TOK_LEN], int tokCount, int tokTypes[]) {
	int curTok = 0;

	/* We need to check the first token to see if the instruction is a declaration. */
	if (toks[curTok][0] == 'i' && toks[curTok][1] == 'n' && toks[curTok][2] == 't') {
		tokTypes[curTok] = INT_TYPE;
	} else if (
		(toks[curTok][0] >= 'a' && toks[curTok][0] <= 'z') || (toks[curTok][0] >= 'A' && toks[curTok][0] <= 'Z')
	) {
		tokTypes[curTok] = VARIABLE;
	}

	/* The rest of the tokens now need to be checked. */
	for (curTok = 1; curTok < tokCount; curTok ++) {
		char temp = toks[curTok][0];

		if (temp == '=') {
			tokTypes[curTok] = ASSIGNER;
		} else if (temp == '+') {
			tokTypes[curTok] = OPERATOR;
		} else if (temp == ';') {
			tokTypes[curTok] = TERMINAL;
		} else if (temp >= '0' && temp <= '9') {
			tokTypes[curTok] = INT_VALUE;
		} else {
			tokTypes[curTok] = VARIABLE;
		}
	}
}

/**
 * Gets the syntax type for the entire instruction.
 *
 * Returns `GOOD_SYNTAX` or `BAD_SYNTAX` depending on certain rules.
 */
int getInstrType(char toks[MAX_TOK_PER_INSTR][MAX_TOK_LEN], int tokCount, int tokTypes[]) {
	/* The last token must be a terminal. */
	if (tokTypes[tokCount - 1] != TERMINAL) {
		return BAD_SYNTAX;
	}

	int hasAssignment = 0;

	/* For declarations, we need to ensure valid syntax. */
	if (tokTypes[0] == INT_TYPE) {
		/* No variable after data type is bad syntax. */
		if (tokTypes[1] != VARIABLE) {
			return BAD_SYNTAX;
		}

		/* Terminal after variable is good syntax. */
		if (tokTypes[2] == TERMINAL) {
			return GOOD_SYNTAX;
		}
	}

	/* Terminal after lone variable is bad syntax. */
	if (tokTypes[0] == VARIABLE) {
		if (tokTypes[1] == TERMINAL) {
			return BAD_SYNTAX;
		}
	}

	/* The location of the assignment operator must be found. */
	int i;
	for (i = 0; i < tokCount; i ++) {
		if (tokTypes[i] == ASSIGNER) {
			hasAssignment = 1;
			i ++;
			break;
		}
	}

	/* If there is no assignment, then it is assumed to be good syntax. */
	if (hasAssignment == 0) {
		return GOOD_SYNTAX;
	}

	/* If assignment is followed by non-variables/non-values, then it is bad syntax. */
	if (tokTypes[i] != VARIABLE && tokTypes[i] != INT_VALUE) {
		return BAD_SYNTAX;
	}

	/* Operator right before terminal is bad syntax. */
	if (tokTypes[tokCount - 2] == OPERATOR) {
		return BAD_SYNTAX;
	}

	/* It should be ensured that operator-variable/value presence is alternating.
	For example: VAR->OP->VAL->OP->VAR is good syntax. */
	i ++;
	for (; i < (tokCount - 1); i ++) {
		if (tokTypes[i] == tokTypes[i - 1]) {
			return BAD_SYNTAX;
		}
	}

	return GOOD_SYNTAX;
}

int main() {
	FILE* code = fopen("sample.txt", "r"); /* The input file name is static; please update to match your local file. */
	char instr[MAX_TOK_LEN * MAX_TOK_PER_INSTR];
	char toks[MAX_TOK_PER_INSTR][MAX_TOK_LEN];
	int tokTypes[MAX_TOK_PER_INSTR];
	int tokCount;
	int tokType;

	/* The file's existence must be checked. */
	if (code == NULL) {
		perror("\nERROR: could not locate file.");
		return EXIT_FAILURE;
	}

	/* The instructions have to be parsed line by line (assuming no discontinuity). */
	while (fgets(instr, MAX_TOK_LEN * MAX_TOK_PER_INSTR * sizeof(char), code)) {
		tokCount = parseInstr(toks, instr);
		getTokTypes(toks, tokCount, tokTypes);
		tokType = getInstrType(toks, tokCount, tokTypes);
		if (tokType == BAD_SYNTAX) {
			printf("ERROR\n\t%s\n", instr);
		} else {
			printf("TRANSFORMATION\n\t%s\n", instr);
		}
	}

	return EXIT_SUCCESS;
}