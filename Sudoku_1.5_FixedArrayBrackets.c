#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
*   Maximum number value/row-/column-count.
*/
#define MAX        9

/**
*   Maximum numbers in puzzle.
*/
#define MAX_PUZZLE  81  //MAX * MAX

/**
*   Maximum sum of all numbers in row/column/square.
*/
#define SUM_MAX     45	//for (int i = MAX; i > 0; sum += i--);

/**
*	Square root of MAX for printing and box size.
*/
#define Square_MAX	3	//sqrt(MAX)

/**
*   The sudoku puzzle matrix.
*/
int sudoku[MAX][MAX] =

/**
*  ---------- MODERATE ----------
*       Iter:         253 calls and          0 guesses in <1ms
*      Recur:       2'431 calls and      1'029 guesses in <1ms
*/
//{ { 0, 0, 0, 0, 0, 0, 0, 9, 0 },
//  { 1, 9, 0, 4, 7, 0, 6, 0, 8 },
//  { 0, 5, 2, 8, 1, 9, 4, 0, 7 },
//  { 2, 0, 0, 0, 4, 8, 0, 0, 0 },
//  { 0, 0, 9, 0, 0, 0, 5, 0, 0 },
//  { 0, 0, 0, 7, 5, 0, 0, 0, 9 },
//  { 9, 0, 7, 3, 6, 4, 1, 8, 0 },
//  { 5, 0, 6, 0, 8, 1, 0, 7, 4 },
//  { 0, 8, 0, 0, 0, 0, 0, 0, 0 } };

/**
*   ------------ HARD ------------
*        Iter:       1'302 calls and          0 guesses in <1ms
*       Recur:     312'830 calls and    150'752 guesses in 28-32ms
*/
//{ { 0, 0, 0, 8, 4, 0, 0, 0, 9 },
//  { 0, 0, 1, 0, 0, 0, 0, 0, 5 },
//  { 8, 0, 0, 0, 2, 1, 4, 6, 0 },
//  { 7, 0, 8, 0, 0, 0, 0, 9, 0 },
//  { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//  { 0, 5, 0, 0, 0, 0, 3, 0, 1 },
//  { 0, 2, 4, 9, 1, 0, 0, 0, 7 },
//  { 9, 0, 0, 0, 0, 0, 5, 0, 0 },
//  { 3, 0, 0, 0, 8, 4, 0, 0, 0 } };

/**
*   -- HARD w/ multi solutions --
*        Iter:       2'852 calls and          6 guesses in <1ms
*       Recur:     128'324 calls and     62'069 guesses in 11ms
*/
{ { 0, 0, 0, 8, 4, 0, 0, 0, 9 },
{ 0, 0, 1, 0, 0, 0, 0, 0, 5 },
{ 8, 0, 0, 0, 2, 0, 4, 6, 0 },
{ 7, 0, 8, 0, 0, 0, 0, 9, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 5, 0, 0, 0, 0, 3, 0, 1 },
{ 0, 2, 4, 9, 1, 0, 0, 0, 7 },
{ 9, 0, 0, 0, 0, 0, 5, 0, 0 },
{ 3, 0, 0, 0, 8, 4, 0, 0, 0 } };

/**
*   ---------- EXTREME ----------
*        Iter:       2'285 calls and          0 guesses in <1ms
*       Recur: 157'353'878 calls and 69'175'316 guesses in 12500-14000ms ~ 13.25s
*/
//{ { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//  { 0, 0, 0, 0, 0, 3, 0, 8, 5 },
//  { 0, 0, 1, 0, 2, 0, 0, 0, 0 },
//  { 0, 0, 0, 5, 0, 7, 0, 0, 0 },
//  { 0, 0, 4, 0, 0, 0, 1, 0, 0 },
//  { 0, 9, 0, 0, 0, 0, 0, 0, 0 },
//  { 5, 0, 0, 0, 0, 0, 0, 7, 3 },
//  { 0, 0, 2, 0, 1, 0, 0, 0, 0 },
//  { 0, 0, 0, 0, 4, 0, 0, 0, 9 } };

/**
*   ----- NEARLY IMPOSSIBLE -----   [ESCARGOT]
*        Iter:      25'740 calls and         84 guesses in  4ms
*       Recur:      21'077 calls and      8'892 guesses in  2ms
*/
//{ { 1, 0, 0, 0, 0, 7, 0, 9, 0 },
//  { 0, 3, 0, 0, 2, 0, 0, 0, 8 },
//  { 0, 0, 9, 6, 0, 0, 5, 0, 0 },
//  { 0, 0, 5, 3, 0, 0, 9, 0, 0 },
//  { 0, 1, 0, 0, 8, 0, 0, 0, 2 },
//  { 6, 0, 0, 0, 0, 4, 0, 0, 0 },
//  { 3, 0, 0, 0, 0, 0, 0, 1, 0 },
//  { 0, 4, 1, 0, 0, 0, 0, 0, 7 },
//  { 0, 0, 7, 0, 0, 0, 3, 0, 0 } };

/**
*   ----- NEARLY IMPOSSIBLE -----   [ARTO INKALA]
*        Iter:      49'089 calls and         94 guesses in  7ms
*       Recur:     121'654 calls and     49'558 guesses in 10ms
*/
//{ { 8, 0, 0, 0, 0, 0, 0, 0, 0},
//  { 0, 0, 3, 6, 0, 0, 0, 0, 0 },
//  { 0, 7, 0, 0, 9, 0, 2, 0, 0 },
//  { 0, 5, 0, 0, 0, 7, 0, 0, 0 },
//  { 0, 0, 0, 0, 4, 5, 7, 0, 0 },
//  { 0, 0, 0, 1, 0, 0, 0, 3, 0 },
//  { 0, 0, 1, 0, 0, 0, 0, 6, 8 },
//  { 0, 0, 8, 5, 0, 0, 0, 1, 0 },
//  { 0, 9, 0, 0, 0, 0, 4, 0, 0 }};



/**
*   Times the solve function is called.
*/
int solveCalls = 0;

/**
*   Times the solver Guessed.
*/
int solveGuess = 0;

/**
*   Fill sudoku matrix with zeros.
*/
void initialiseSudoku() {
	for (int i = 0; i < MAX; i++)
		for (int j = i; j < MAX; j++) {
			if (i != j) sudoku[j][i] = 0;
						sudoku[i][j] = 0;
		}
}

/**
*   Read and store a new sudoku.
*/
int readSudoku(int readFromCmd, char newS[MAX_PUZZLE]) {
	int i, j, digits = 0, tmp;
	if (readFromCmd) {  //  Read from cmd-line args : convert char string to int matrix
		for (i = 0, j = 0; i < MAX_PUZZLE; j++) {
			tmp = newS[j] - '0';
			if (tmp >= 0 && tmp <= MAX) { digits += (sudoku[i / MAX][i % MAX] = tmp) >= 0; i++; }
		}
	}
	else {            //  Read from user input
		printf("Enter sudoku numbers, 0 for empty:\n");
		for (i = 0; i < MAX; i++)
			for (j = 0; j < MAX; j++)
				digits += scanf("%1d", &sudoku[i][j]);
	}
	return digits;
}

/**
*   Transpose the sudoku matrix.
*/
void transposeSudoku() {
	for (int i = 0; i < MAX; i++)
		for (int j = i; j < MAX; j++)
			if (i != j) {
				int tmp = sudoku[j][i];
				sudoku[j][i] = sudoku[i][j];
				sudoku[i][j] = tmp;
			}
}

/**
*   Prints sudoku matrix.
*/
void printSudoku() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (sudoku[i][j])   printf("%d", sudoku[i][j]);
			else                printf(".");
			printf("%s", !((j + 1) % Square_MAX) && j < MAX - 1 ? "|" : " ");
		}
		if (!((i + 1) % Square_MAX) && i < MAX - 1) {
			printf("\n");
			for (int j = 0; j < (MAX * 2 - 1); j++)
				printf("%s", j == SUM_MAX / MAX ? "+" : "-");
		}
		printf("\n");
	}
}

/**
*   Check if sudoku is valid by counting row/col/box totals.
*       Returns 0 if sum != 45
*/
int validateSudoku() {
	// Count columns, rows, boxes
	for (int i = 0, j, sumRow, sumCol, sumBox, rowStart, colStart; i < MAX; i++) {
		rowStart = (i / Square_MAX) * Square_MAX, colStart = (i % Square_MAX) * Square_MAX;
		for (j = sumRow = sumCol = sumBox = 0; j < MAX; j++) {
			if (!sudoku[i][j] || !sudoku[j][i]) return 0;
			sumRow += sudoku[i][j];
			sumCol += sudoku[j][i];
			sumBox += sudoku[rowStart + (j % Square_MAX)][colStart + (j / Square_MAX)];
		}
		if (sumRow != SUM_MAX || sumCol != SUM_MAX || sumBox != SUM_MAX) return 0;
	}
	return 1;
}

/**
*   Check if a number can be set at a given location.
*/
int canSetNumber(int row, int col, int num) {
	if (sudoku[row][col]) return 0;

	int rowStart = (row / Square_MAX) * Square_MAX, colStart = (col / Square_MAX) * Square_MAX;

	for (int i = 0; i < MAX; i++) {  // Return 0 if number already present in row/col/box
		if (sudoku[i][col] == num) return 0;
		if (sudoku[row][i] == num) return 0;
		if (sudoku[rowStart + (i % Square_MAX)][colStart + (i / Square_MAX)] == num) return 0;
	}
	return 1;
}

/**
*   Recursively try to solve sudoku by entering numbers and backtracking if invalid solution.
*/
int solveSudoku(int sudoku[][MAX], int row, int col) {
	if (row < MAX && col < MAX) {
		solveCalls++; //---
		if (sudoku[row][col]) { //  Move to next square
			if		(col + 1 < MAX)      return solveSudoku(sudoku, row, col + 1);
			else if (row + 1 < MAX)      return solveSudoku(sudoku, row + 1, 0);
			else						 return 1;
		}
		else                  //  For each possible digit, try guessing
			for (int digit = 1; digit <= MAX; digit++)
				if (canSetNumber(row, col, digit)) {
					sudoku[row][col] = digit;
					solveGuess++; //---
					if (solveSudoku(sudoku, row, col)) return 1;
					else sudoku[row][col] = 0;
				}
		return 0;
	}
	return 1;
}

/**
*   Compare 2 integer arrays and return '1' if equal
*/
int compareTupleArray(int tuple1[], int tuple2[]) {
	for (int i = 0; i < MAX; i++)
		if (tuple1[i] != tuple2[i]) return 0;
	return 1;
}

/**
*   Compare 2 or more X or Y positions in possibility array with each other or value.
*/
int equal_ValueOrPossibility_XY(int X, int value, int pos[]) {
	int i, ret = 1, start = 2 - X;
	if (value < 0)	for (i = 1; i < pos[0]; i++) ret &= (pos[start] == pos[start + 2 * i]);
	else			for (i = 0; i < pos[0]; i++) ret &= (value != pos[start + 2 * i]);
	return ret;
}

/**
*   Copy sudoku matrix to other matrix.
*/
void copySudokuTo(int from[][MAX], int to[][MAX]) {
	for (int x = 0; x < MAX; x++)
		for (int y = x; y < MAX; y++) {
			if (x != y) to[y][x] = from[y][x];
						to[x][y] = from[x][y];
		}
}

/**
*   Iteratively try solving.
*       Methods reference: http://www.sudokuwiki.org/sudoku.htm
*/
int solveSudokuIter(int sudoku[][MAX]) {
	//  Sudoku[9][9]-[9] tuples/helpvars :: the possible candidates for a square
	int sudokuTuples[MAX][MAX][MAX];

	// Initialise tuples
	for (int i = 0; i < MAX; i++)
		for (int j = i; j < MAX; j++)
			for (int digit = 1; digit <= MAX; digit++) {
				if (i != j) sudokuTuples[j][i][digit - 1] = canSetNumber(j, i, digit);
							sudokuTuples[i][j][digit - 1] = canSetNumber(i, j, digit);
			}

	//Try solving
	for (int didSomething = 1; didSomething & !validateSudoku();) {
		didSomething = 0;
		//  Find (Hidden) singles   ::  Tuples that only occur once in row/col/sq
		for (int i = 0, foundSingle; i < MAX; i++) {
			foundSingle = 0;
			for (int j = 0; j < MAX; j++) {
				if (!sudoku[i][j]) {
					for (int k = 0; k < MAX; k++) {
						if (sudokuTuples[i][j][k]) {    // Fore each square & for each tuple in square
							int isSingleSqr = 1, isSingleRow = 1, isSingleCol = 1, isSingleBox = 1;
							solveCalls++;//---

							//  Check tuples from square/row/col/box if [k] is present
							int rowStart = (i / Square_MAX) * Square_MAX, colStart = (j / Square_MAX) * Square_MAX, tmpRow, tmpCol;
							for (int l = 0; l < MAX; l++) {
								if (isSingleSqr & l != k & sudokuTuples[i][j][l]) isSingleSqr = 0;
								if (isSingleRow & l != i & sudokuTuples[l][j][k]) isSingleRow = 0;
								if (isSingleCol & l != j & sudokuTuples[i][l][k]) isSingleCol = 0;
								tmpRow = rowStart + (l % Square_MAX); tmpCol = colStart + (l / Square_MAX);
								if (isSingleBox & !(tmpRow == i && tmpCol == j) && sudokuTuples[tmpRow][tmpCol][k]) isSingleBox = 0;
							}

							//  If tuple occurs once in row/col/sq, remove it from others
							if (isSingleSqr || isSingleRow || isSingleCol || isSingleBox) {
								//  Set value
								sudoku[i][j] = k + 1;
								for (int m = 0; m < MAX; sudokuTuples[i][j][m++] = 0);

								//  Remove tuples from row/col/square
								for (int l = 0; l < MAX; l++) {
									sudokuTuples[l][j][k] = 0;
									sudokuTuples[i][l][k] = 0;
									sudokuTuples[rowStart + (l % Square_MAX)][colStart + (l / Square_MAX)][k] = 0;
								}
								didSomething = foundSingle = 1;
								break;
							}
						}
					}
				}
			}
			if (foundSingle) i = -1;    //Retry when found at least one
		}

		//  Find Naked Pairs    ::  Pair of 2 tuples in row/col/sq
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				if (!sudoku[i][j]) {    //  For each sq in puzzle
					int tuples = 0, pos1 = 0, pos2 = 0;
					solveCalls++;//---

					//  Count tuples for pair
					for (int k = 0; k < MAX; k++)
						if (sudokuTuples[i][j][k])  {
							tuples++;
							if (!pos1)  pos1 = k;
							if (pos1)   pos2 = k;
						}

					//  Square has tuple pair
					if (tuples == 2) {
						//  Find matching tuple in row/col/square
						int inRow = 0, rowPos, inCol = 0, colPos, inBox = 0, tmpRow, tmpCol, boxP_X, boxP_Y;
						int rowStart = (i / Square_MAX) * Square_MAX, colStart = (j / Square_MAX) * Square_MAX;
						for (int l = 0; l < MAX; l++) {
							if (l != i && compareTupleArray(sudokuTuples[i][j], sudokuTuples[l][j])) { inRow++; rowPos = l; }
							if (l != j && compareTupleArray(sudokuTuples[i][j], sudokuTuples[i][l])) { inCol++; colPos = l; }
							tmpRow = rowStart + (l % Square_MAX); tmpCol = colStart + (l / Square_MAX);
							if (tmpCol != i && tmpCol != j && compareTupleArray(sudokuTuples[i][j], sudokuTuples[tmpRow][tmpCol])) {
								inBox++; boxP_X = tmpRow, boxP_Y = tmpCol;
							}
						}

						//  Remove other tuples in row/col/box that are in found pair
						if (inRow == 1) {
							for (int m = 0; m < MAX; m++) {
								if (m != i & m != rowPos) {
									sudokuTuples[m][j][pos1] = 0;
									sudokuTuples[m][j][pos2] = 0;
								}
							}
						}
						if (inCol == 1) {
							for (int m = 0; m < MAX; m++) {
								if (m != j & m != colPos) {
									sudokuTuples[i][m][pos1] = 0;
									sudokuTuples[i][m][pos2] = 0;
								}
							}
						}
						if (inBox == 1) {
							for (int m = 0; m < MAX; m++) {
								tmpRow = rowStart + (m % Square_MAX); tmpCol = colStart + (m / Square_MAX);
								if (tmpRow != i & tmpCol != j &  tmpRow != boxP_X & tmpCol != boxP_Y) {
									sudokuTuples[rowStart + (m % Square_MAX)][colStart + (m / Square_MAX)][pos1] = 0;
									sudokuTuples[rowStart + (m % Square_MAX)][colStart + (m / Square_MAX)][pos2] = 0;
								}
							}
						}
					}
				}
			}
		}

		//  Pointing Pairs/Triples AND Box/Line Reduction
		for (int i = 0, rowStart, colStart; i < MAX; i++) {      // For each box
			int possibilities[MAX][MAX * 2 + 1] = { { 0 } };
			rowStart = (i / Square_MAX) * Square_MAX, colStart = (i % Square_MAX) * Square_MAX;
			solveCalls++;//---

			for (int j = 0, x, y; j < MAX; j++) {                //  For Each square in box
				x = rowStart + (j % Square_MAX); y = colStart + (j / Square_MAX);
				if (!sudoku[x][y]) {
					for (int k = 0; k < MAX; k++) {              //      For each possible value in square
						if (sudokuTuples[x][y][k]) {
							possibilities[k][0]++;              // x + 1 :: because checks if(pos), else: false if pos happens to be 0
							for (int l = 0, tmp; l < MAX; l++)
									if (!possibilities[k][(tmp = 1 + 2 * l)]) {
										possibilities[k][tmp] = x + 1; possibilities[k][tmp + 1] = y; break;
									}
						}
					}
				}
			}

			//  Remove other occurrences in row/col if pair/triple in same row/col
			for (int j = 0; j < MAX; j++) {
				// Correct compare values
				for (int k = 0; k < MAX; k++) possibilities[j][1 + 2 * k]--;

				if (possibilities[j][0] == 2 || possibilities[j][0] == 3) {
					if (equal_ValueOrPossibility_XY(1, -1, possibilities[j])) {         //Equal row
						for (int k = 0; k < MAX; k++) // Remove value from rest of row
							if (equal_ValueOrPossibility_XY(0, k, possibilities[j])) sudokuTuples[possibilities[j][1]][k][j] = 0;
					}
					else if (equal_ValueOrPossibility_XY(0, -1, possibilities[j])) {  //Equal col
						for (int k = 0; k < MAX; k++) // Remove value from rest of col}
							if (equal_ValueOrPossibility_XY(1, k, possibilities[j])) sudokuTuples[k][possibilities[j][2]][j] = 0;
					}
				}

				//  Box/Line Reduction
				//  count possibilities in row/col if no other than those in row/col of box, remove other occurrences from box
				if (possibilities[j][0] > 2) {
					int inRow = 0, inCol = 0;
					for (int k = 0; k < MAX; k++) {
						if (equal_ValueOrPossibility_XY(0, k, possibilities[j]) & sudokuTuples[possibilities[j][1]][k][j]) inRow++;
						if (equal_ValueOrPossibility_XY(1, k, possibilities[j]) & sudokuTuples[k][possibilities[j][2]][j]) inCol++;
					}

					if (!inRow) {   //  Only in box-row/col: remove from rest of box
						for (int k = 0, x, y; k < MAX; k++) {
							x = rowStart + (k % Square_MAX); y = colStart + (k / Square_MAX);
							if (x != possibilities[j][1]) sudokuTuples[x][y][j] = 0;
						}
					}
					else if (!inCol) {
						for (int k = 0, x, y; k < MAX; k++) {
							x = rowStart + (k % Square_MAX); y = colStart + (k / Square_MAX);
							if (y != possibilities[j][2]) sudokuTuples[x][y][j] = 0;
						}
					}
				}
			}
		}

		//  X-Wing  ::  Tuple occurs only twice in row/col? => find common pair in same col/row and remove rest from col/row
		if (!didSomething) {
			int possibilitiesRow[MAX][MAX][5] = { { 0 } };  //row, tuple count, pos1_X, pos1_Y, pos2_X, pos2_Y
			int possibilitiesCol[MAX][MAX][5] = { { 0 } };  //col

			for (int i = 0; i < MAX; i++) {      // For row/col
				for (int j = 0; j < MAX; j++) {      //  For Each square in row/col
					if (!sudoku[i][j]) {
						for (int k = 0; k < MAX; k++) {  //  For each possible value in square
							if (sudokuTuples[i][j][k]) {
								possibilitiesRow[i][k][0]++;                // i + 1 :: because checks if(pos), else: false if pos happens to be 0
								if		(!possibilitiesRow[i][k][1])    { possibilitiesRow[i][k][1] = i + 1; possibilitiesRow[i][k][2] = j; }
								else if (!possibilitiesRow[i][k][3])    { possibilitiesRow[i][k][3] = i + 1; possibilitiesRow[i][k][4] = j; }

								possibilitiesCol[j][k][0]++;                // i + 1 :: because checks if(pos), else: false if pos happens to be 0
								if		(!possibilitiesCol[j][k][1])    { possibilitiesCol[j][k][1] = i + 1; possibilitiesCol[j][k][2] = j; }
								else if (!possibilitiesCol[j][k][3])    { possibilitiesCol[j][k][3] = i + 1; possibilitiesCol[j][k][4] = j; }
							}
						}
					}
				}
			}

			for (int k = 0; k < MAX; k++) {  //For each tuple
				for (int i = 0; i < MAX; i++) {      //in Row/Col
					solveCalls++;//---
					if (possibilitiesRow[i][k][0] == 2) {
						int rowOther = -1;
						//Find other row with tuple i count == 2 && 2 tuples in same col
						for (int j = i + 1; j < MAX; j++)
							if (possibilitiesRow[j][k][0] == 2 & possibilitiesRow[i][k][2] == possibilitiesRow[j][k][2] & possibilitiesRow[i][k][4] == possibilitiesRow[j][k][4]) {
								rowOther = j; break;
							}

						//Other row found :: X-Wing! => remove other occurrence of tuple in cols
						if (rowOther > 0)
							for (int j = 0; j < MAX; j++)
								if (j != i && j != rowOther) {
									sudokuTuples[j][possibilitiesRow[i][k][2]][k] = 0;
									sudokuTuples[j][possibilitiesRow[i][k][4]][k] = 0;
								}
						break;
					}
					else if (possibilitiesCol[i][k][0] == 2) {
						// Correct compare values
						possibilitiesCol[i][k][1]--; possibilitiesCol[i][k][3]--;

						int colOther = -1;
						//Find other col with tuple i count == 2 && 2 tuples in same row
						for (int j = i + 1; j < MAX; j++)
							if (possibilitiesCol[j][k][0] == 2 & possibilitiesCol[i][k][1] == --possibilitiesCol[j][k][1] & possibilitiesCol[i][k][3] == --possibilitiesCol[j][k][3]) {
								colOther = j; break;
							}

						//Other col found :: X-Wing! => remove other occurrence of tuple in rows
						if (colOther > 0)
							for (int j = 0; j < MAX; j++)
								if (j != i && j != colOther) {
									sudokuTuples[possibilitiesCol[i][k][1]][j][k] = 0;
									sudokuTuples[possibilitiesCol[i][k][3]][j][k] = 0;
								}
						break;
					}
				}
			}
		}
	}

	//  Try guessing and backtrack if not solved
	if (!validateSudoku()) {
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				if (!sudoku[i][j]) {
					int tuples = 0, digit1 = 0, digit2 = 0;
					solveCalls++;//---

					//Count tuples for 2
					for (int digit = 1; digit <= MAX; digit++)
						if (sudokuTuples[i][j][digit - 1]) {
							tuples++;
							if (!digit1)    digit1 = digit;
							if (digit1)     digit2 = digit;
						}

					if (tuples == 2) {
						int oldSudoku[MAX][MAX];
						//copy :: old <- new
						copySudokuTo(sudoku, oldSudoku);

						//guess
						sudoku[i][j] = digit1;
						solveGuess++; //---
						if (solveSudokuIter(sudoku))
							return 1;
						else {
							//Restore
							copySudokuTo(oldSudoku, sudoku);

							//Guess again with other
							sudoku[i][j] = digit2;
							solveGuess++; //---
							return solveSudokuIter(sudoku);
						}
					}
				}
			}
		}
	}

	//  Print All Tuples with: Position : value : tuples
	//for (int i = 0; i < MAX; i++)
	//  for (int j = 0; j < MAX; j++) {
	//      printf("(%d,%d) : %d : ", i, j, sudoku[i][j]);
	//      for (int k = 0; k < MAX; printf("%d ",sudokuTuples[i][j][k++]));
	//      putchar('\n');
	//  }

	return validateSudoku();
}

int printMsg(int solved, clock_t time) {
	if (solved) {
		printf("\nSolved!\nValid? %s  ::  solveCalls = %d  ::  solveGuess = %d  ::  Time = %dms\n\n", validateSudoku() ? "yes" : "no", solveCalls, solveGuess, time);
		printSudoku(sudoku);
	}
	else {
		printf("\nCannot solve sudoku.\nsolveCalls = %d : solveGuess = %d  ::  Time: %dms\n", solveCalls, solveGuess, time);
		solveCalls = solveGuess = 0;
	}
	return solved;
}

/**
*   Main method
*       Cmd-line    ::  argc    = number of arguments
*                       argv[]  = arguments with:   argv[0] : this program
*                                                   argv[1] : 'n' or 'i'
*                                                   argv[2] : for 'n' -> char[MAX_PUZZLE] (the new puzzle)
*       Regular     ::  Ask for (N)ew or (I)nternal sudoku and tries solving
*/
int main(int argc, char *argv[]) {
	clock_t start = 0, elapsedTime = 0;
	int backupSudoku[MAX][MAX];
	char input = (argc > 1 ? argv[1][0] : NULL);

	printf("-------------------------------- SUDOKU SOLVER --------------------------------\n");
	if (input == NULL)  //  When no method given, ask.
		do {
			printf("Read (N)ew puzzle with spaces/continuous string or use (I)nternal (N/I)? ");
			scanf(" %c", &input);
		} while (input != 'n' && input != 'N' && input != 'i' && input != 'I');

	//  Initialise and read new puzzle. Exit if already solved or invalid input.
	if (input == 'n' || input == 'N') {
		initialiseSudoku();
		int readAllDigits = (readSudoku(argc > 2, argv[2]) == MAX_PUZZLE);
		if (!readAllDigits | validateSudoku()) {
			printMsg(readAllDigits, 0);
			system("PAUSE");
			return 0;
		}
	}

	//  Back-up initial puzzle
	copySudokuTo(sudoku, backupSudoku);

	//Transpose? ---------> transposeSudoku();

	printf("\nInitial state:\n--------------\n");
	printSudoku(sudoku);

	printf("Trying to solve...\n");
	start = clock();                //  Get start time
	int solved = solveSudokuIter(sudoku);
	elapsedTime = clock() - start;  //  Calculate elapsed time since solving started for time complexity

	if (!printMsg(solved, elapsedTime)) {
		printf("\nRetrying from start with recursion...\n");
		copySudokuTo(backupSudoku, sudoku);

		start = clock();
		solved = solveSudoku(sudoku, 0, 0);
		elapsedTime = clock() - start;

		printMsg(solved, elapsedTime);
	}

	printf("\n");
	system("PAUSE");
	return 0;
}
