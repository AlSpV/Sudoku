# Sudoku
C program which can solve any sudoku with sizes 4x4, 9x9, 16x16 and 25x25,  
using an iterative algorithm as described in the code and <a href=http://www.sudokuwiki.org/sudoku.htm>here</a>.

Sudoku's are parsed from input, continuous stream of digits for 4x4 or 9x9 sudoku's and  
digit separated by a white-space (space or return), both from user input or command line.  


<b>_sampleSudokus.txt</b>  
A list of 9x9 sudoku's for testing purposes, can be run with _testSudokuFromFile.bat

<b>16x16-easy.txt</b>  
A 16x16 easy sudoku (copy-paste as user input to test)

<b>16x16-medium.txt</b>  
A 16x16 medium sudoku (copy-paste as user input to test)

<b>25x25-easy.txt</b>  
A 25x25 easy sudoku (copy-paste as user input to test)

<b>Sudoku_1.5_FixedArrayBrackets.c</b>  
The previous version with fixed array sizes, 9x9 sudokus only.

<b>Sudoku_2.0_DynamicArrayAlloc.c</b>  
The latest version with memory allocation.
