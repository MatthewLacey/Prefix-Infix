Infix/Prefix Converter
======================
##### Matthew Lacey
##### CSCI 61
##### Fall 2017

#### Assignment Description
> Write a C++ program that can take in a mathematical expression in "infix" or "prefix" notation and convert it to the other notation. If you do not remember infix and prefix notations from math class, the following link can help refresh your memory: http://www.cs.man.ac.uk/~pjj/cs212/fix.html

#### To Execute Program:
1. Compile main.cpp
 `g++ main.cpp`
2. Run the resulting a.out file
 `./a.out`

#### Limitations:
This program can take in any infix notation equation and return it in prefix notation. Whitespace will create no issues. However *whitespace is very important when inputting a prefix equation for conversion to infix notation*. Failure to put whitespace between operands will result in an error. For instance "+87" will return an error because the program assumes you are trying to add 87 to nothing. You must write "+ 8 7" to achieve the desired result of eight plus seven.
 
#### Suggested Test Cases:
##### Infix to Prefix:
`890 * (9 - 78) / e^6 - 2`
##### Prefix to Infix:
`- / * 890 - 9 78 ^ e 6 2`