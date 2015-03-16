@echo off
cls

REM	Place with '_sampleSudokus.txt' in same folder as executable.
REM	Rename 'sudokuSolver.exe' if needed.

FOR /F "tokens=*" %%i in (_sampleSudokus.txt) DO (
	sudokuSolver.exe n 9 %%i
	cls
)

PAUSE
