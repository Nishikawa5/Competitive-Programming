
ScoreOfCellsMarks: 100
Problem Description
James is a school going kid, who just learned about rows, columns and tables. On one fine day, he drew a table consisting of n rows and m columns. In each cell, he wrote a number randomly.

James defined a concept "score" for each cell. The score of a cell A is the number of unique ways possible from all the cells to reach A. For this, he has to follow a rule which states that, he can only move from current cell to either down/right cell only if the value those cells hold is not lesser than the value in the current cell.

Given an integer k, find out the cells with score k. If there are more than one cell, then print the indices of the cells in the order they occur in the table from left to right and top to bottom. Print "NO" if there are no cells with such score.

Note: Two ways are said to be unique if they have at least one different cell in its path.

Constraints
1 <= n,m <= 100

0 <= table[i] <= 10^4

Input
First line contains two integers n,m separated by space.

Next n lines contain the values in the cells of the table.

Next line contains an integer k.

Output
Print the indices of cell(s) with given score in separate lines.

Refer to Examples section for better understanding.

Time Limit (secs)
1

Examples
Example 1

Input

4 3

6 4 5

8 5 3

9 7 2

1 9 10

1

Output

0 2

1 0

1 1

Explanation-

The score of a cell A is the number of unique ways possible from all the cells to reach A.

For the cell [0,2], [0,1] -> [0,2] is the only possible way.

For the cell [1,0], [0,0] -> [1,0] is the only possible way.

For the cell [1,1], [0,1] -> [1,1] is the only possible way.

So, the score of all these cells is 1 and we print them in the order of their occurrence.

Example 2

Input

3 3

6 16 19

14 20 17

21 12 11

4

Output

1 1

Explanation-

The score of a cell A is the number of unique ways possible from all the cells to reach A.

For the cell [1,1], four ways are possible.

[0,0] -> [1,0] -> [1,1], [0,0] -> [0,1] -> [1,1], [1,0] -> [1,1], [0,1] -> [1,1]

So the score of [1,1] is 4 and we print it as output.