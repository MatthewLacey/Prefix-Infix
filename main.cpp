// Matthew Lacey
// CSCI 61 HW01

#include <iostream>
#include <stack>      // Provides the stack template class
#include <string>
using namespace std;

// Function Prototypes
string prefixToInfix(string prefix);
string infixToPrefix(string infixS);
string reverseStr(string input);
int pemdas(string input);
bool isOperator(string symbol);
string message(int flag);
void menu();
void printStack(stack<string> s); // for debugging

// Define Main Function
int main() {
	menu();
	return 0;
}

// Convert Infix Notation to Prefix
string infixToPrefix(string infixS) {
	stack<string> infix;
	infixS = reverseStr(infixS);
	for (char &c: infixS){
		if(c != ' ')
			infix.push(string(1, c));
	}
	string prefix; // string to contain result (input equation in infix notation)
	stack<string> ops; // stack to hold operators
	stack<string> buffer; // stack to assist in the formation of the prefix equation
	
	//Loops for as many characters are in the input infix equation
	while(!infix.empty()){
		// if the current character is not an operator, assume it is 
		// an operand and add to buffer stack
		if(!isOperator(infix.top())){
			string num = infix.top();
			infix.pop();
			while(!infix.empty()){
				if(!isOperator(infix.top())){
					num = infix.top() + num;
					infix.pop();
				}
				else
					break;
			}
			buffer.push(num);
		}
		else if ( infix.top() == "(" || ops.empty() || pemdas(infix.top()) > pemdas(ops.top()) ){
			ops.push(infix.top());
			infix.pop();
		}
		else if ( infix.top() == ")"){
			while(ops.top() != "("){
				/* the following six lines of code is repeated throughout
				this function. (because nested functions arent allowed
				for some reason) They take the last two "blocks" being
				operated on by the operator from the buffer stack and 
				flip them around. This ensures that something like
				C / D translates to /CD instead of /DC */
				string operand1 = buffer.top();
				buffer.pop();
				string operand2 = buffer.top();
				buffer.pop();
				buffer.push(operand1 + " " + operand2 + " " + ops.top());
				ops.pop();
			}
			ops.pop(); // remove the '(' from the stack
			infix.pop();
		}
		else if ( pemdas(infix.top()) <= pemdas(ops.top()) ){
			while(!ops.empty() && pemdas(infix.top()) <= pemdas(ops.top())){
				string operand1 = buffer.top();
				buffer.pop();
				string operand2 = buffer.top();
				buffer.pop();
				buffer.push(operand1 + " " + operand2 + " " + ops.top());
				ops.pop();
			}
			ops.push(infix.top()); // push current char onto ops stack
			infix.pop();
		}

	}
	while(!ops.empty()){
		string operand1 = buffer.top();
		buffer.pop();
		string operand2 = buffer.top();
		buffer.pop();
		buffer.push(operand1 + " " + operand2 + " " + ops.top());
		ops.pop();
	}
	prefix = reverseStr(buffer.top());
	return prefix;
}

// Convert Prefix Notation to Infix
string prefixToInfix(string prefixS) {
	// reverse input so operators come after operands
	stack<string> prefix;
    for (char &c: prefixS){
            prefix.push(string(1, c));
    }
	string infix; // final infix notation string returned by function
	stack<string> buffer; // stack to help in formation of final equation
	while(!prefix.empty()){
		// if the current character is not an operator, assume it is 
		// an operand and add to buffer stack
        if(!isOperator(prefix.top())){
            string num;
            while(!prefix.empty()){
                if(prefix.top().compare(" ") == 0){
                    prefix.pop();
                    break;
                }

                else if(!isOperator(prefix.top())){
                    num = prefix.top() + num;
                    prefix.pop();
                }
                else
                    break;
            }
            buffer.push(num);
        } else {
			auto operand1 = buffer.top();
			buffer.pop();
            auto operand2 = buffer.top();
			buffer.pop();
            string result = operand1 + prefix.top() + operand2;
            prefix.pop();
            if (!prefix.empty()){
                buffer.push("(" + result + ")");
                while(!prefix.empty()){
                    if(prefix.top().compare(" ") == 0){
                        prefix.pop();
                    }
                    else
                        break;
                }
            }
            else
                buffer.push(result);


		}
	}
	infix = buffer.top();
	return infix;
}

// Reverses content of a String
string reverseStr(string input) {
	string output = input;
	for(int i = 0; i < input.length()/2; i++)
		swap(output[i], output[input.length()-i-1]);
	return output;
}

// Assigns Order of Operations (Not including parenthesis)
int pemdas(string input) {
	switch(input[0]) {
		case '+':
		case '-':
			return 1;
			break;
		case '*':
		case '/':
			return 2;
			break;
		case '^':
			return 3;
			break;
		default:
			return -1;
			break;
	}
}

// Checks to see if a character is a mathematical operator
bool isOperator(string symbol) {
	switch(symbol[0]) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case '(':
		case ')':
		        return true;
		default:
		        return false;
		// returns false if the symbol is other than given above
	}
}

string message(int flag){
	switch(flag){
		case 1:
			return 	"********************************************\n   Welcome to the Infix/Prefix Converter!\n\n i: input equation in infix notation\n    and get equation in prefix notation\n p: input equation in prefix notation\n    and get equation in infix notation\n h: reprint this message\n q: exit program\n********************************************\n\n>> ";
		case 2:
			return "Enter Infix Equation >> ";
		case 3:
			return "Enter Prefix Equation >> ";
		default:
			return "ERROR";
	}
}

void menu(){
	char input = 'h';
	string inputS;

	while(input != 'q'){
		switch(input){
			case 'i':
				cout << message(2);
                cin.ignore();
				getline(cin, inputS);
				cout << infixToPrefix(inputS) << "\n\n>> ";
				break;
			case 'p':
				cout << message(3);
                cin.ignore();
                getline(cin, inputS);
				cout << prefixToInfix(inputS) << "\n\n>> ";
				break;
			case 'h':
				cout << message(1);
				break;
			case 'q':
				break;
			default:
				cout << "Invalid input. type 'h' for help.\n>> ";
		}
		cin >> input;
	}
}

void printStack(stack<string> s){
    cout << "---------\n";
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    cout << "---------\n";

}




