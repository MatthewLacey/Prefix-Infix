prefix-infix
============
A program that asks the user to enter a math expression in infix or prefix notation, converts it to the other notation, and prints out the result. The program will run until the user enters 'q' to quit.

To compile: `g++ -std=c++11 main.cpp -o prefix-infix`

##Notes:
- All symbols other than the following operators (,),^,*,/,+,- will be considered operands

- User must enter a valid mathematical expression in either infix or prefix notation

- This program can take in any infix notation equation and return it in prefix notation. Whitespace will create no issues. However *whitespace is very important when inputting a prefix equation for conversion to infix notation*. Failure to put whitespace between operands will result in an error. For instance "+87" will return an error because the program assumes you are trying to add 87 to nothing. You must write "+ 8 7" to achieve the desired result of eight plus seven.

- Utilizes stacks for implementation

##Sample Test Cases:
Order of operations
```
	       Infix: 1*2+3/4
	       Prefix: +*12/34

	       Prefix: +*12/34
	       Infix: ((1*2)+(3/4))
```         

Parentheses within expression
```
	       Infix: 1*(2+3)/4
	       Prefix: /*1+234

	       Prefix: /*1+234
	       Infix: ((1*(2+3))/4)
```        

Parentheses with order of operations inside
```
	       Infix: 1*(2+3/4)
	       Prefix: *1+2/34

	       Prefix: *1+2/34
	       Infix: (1*(2+(3/4)))
```

Parentheses outside expression	
```
	       Infix: ((1*2)+(3/4))
	       Prefix: +*12/34
```
##Output:
![Example Output](https://user-images.githubusercontent.com/18524488/50881629-14b66d00-1397-11e9-8fb0-f5312a5aac6c.png)