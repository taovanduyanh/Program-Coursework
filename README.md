# Coursework

//////////////////////////////////////////////

Tasks:

✔ Create a program that will allow a user to manually type in a 15-puzzle configuration
using numbers 1 through 20 (inclusive)
 
✔ Make sure not to allow repeated numbers for the blocks

✔ Create a program that will create 15-Puzzle configurations using numbers 1 through 20
(inclusive) in a pseudo random way
  
  ○ The number of these configurations can be chosen by the user

✔ Produce a text file (the 15-File) that stores 15-Puzzle configurations that your program
generates

  ✔ Text file format should start with a single number (indicating the number of
15-Puzzle squares) followed by the squares themselves (see below). Block
labels should be separated by a space and each row should be on a new line

2

1 2 3 4

5 6 7 8

9 10 11 12

13 20 15

1 3 2 4

5 6 7 8

9 10 11 12

13 20 15

✔ Allow your program to read in a file (the 15-File) and deduce how many continuous rows,
continuous columns, reverse continuous rows and reverse continuous columns are
possible for all turns from the given configuration and print this to screen

1

1 2 3 4

5 6 7 8

9 10 11 12

13 20 15

row = 2302

column = 2344

reverse row = 2341

reverse column = 2341

✔ Allow your program to output its findings to a text file (the Solution-File) shown using the
format above

✔ Compare your results with your friends and colleagues in class to ensure your program
is correct
○ Read in the 15-Puzzle files of your colleagues and check their answers against
your own (Solution-Files) (the numbers shown here in this document may be
indicative only and not a true representation of an accurate solution)

✔ Using a method of your choice, extend your solution from coursework 1 to identify all
3-partial continuous row and 3-partial continuous column (including reverse) in any given
15-Puzzle configuration

✔ Extend your solution to identify all 3-partial continuous row and 3-partial continuous
column (including reverse) in all reachable 15-Puzzle configurations using valid “turns”
from any given valid 15-Puzzle configuration

✔ Ensuring your user interface still allows manual and random 15-Puzzle generation,
extend your interface to allow a user to request the finding of either 2, 3, or 4 -partial
continuous row/column (including reverse) in any given 15-Puzzle configuration (as
requested by a user - random or manual)
1

✔ Allow your user to request the finding of 2, 3, or 4 -partial continuous column/row
(including reverse) 15-Puzzle configurations reachable using valid “turns” from any given
valid 15-Puzzle configuration

✔ Enhance your Solution-File to add the values for partial continuous solutions (the
numbers shown here may be indicative only and not a true representation of an accurate
solution):

2

1 2 3 4

5 6 7 8

9 10 11 12

13 20 15

row = 2302

column = 2344

reverse row = 2341

reverse column = 2341

(total for row & column, including reverse, in this configuration)

2 = 22

3 = 14

4 = 8

(total for row and column, including reverse, for all valid turns)

2 = 235223

3 = 34563

4 = 456

✔ Check your solution for correctness with friends and colleagues in the class

✔ Update your solution to allow the user to specify the size of the 15-Puzzle problem (e.g.,
25-Puzzle, 36-Puzzle, 49-Puzzle)
