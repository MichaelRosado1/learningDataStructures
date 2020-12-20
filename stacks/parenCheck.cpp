#include <vector>
#include <iostream> 
#include <string>


#define defaultSizeOfStack 1000

class Stack {
	int stackIndex;	
	public:
		char items[defaultSizeOfStack];

		Stack() {
			stackIndex = -1;
		}
		
		void push(char element) {
			//if index is at more than 999, the index will go out of the array bounds
			if (this->stackIndex >= defaultSizeOfStack - 1) {
				std::cout<<"Stack overflow!"<<std::endl;
			} else {
				this->stackIndex++;
				//sets  next index = the the given char
				this->items[stackIndex] = element;
			}

		}

		void pop() {
			if (this->stackIndex < 0) {
				std::cout<<"Stack underflow!"<<std::endl;
			} else {
				this->items[stackIndex] = ' ';
				this->stackIndex--;
			}	
		}

		char peek() {
			if (stackIndex == -1) {
				std::cout<<"stack is empty";
				return ' ';
			} else {
				return this->items[stackIndex];		
			}
		}

		bool isNOTEmptyOrFull() {
			if (this->stackIndex == -1) {
				return false;
			} else {
				return true;
			}
		}
};

bool checkIfStringIsEqual(std::string str) {
	/*
		1) convert the string to a char vector
		2) for each letter in the vector, check if it is an ) or (
			if it is (, push the char to the stack
			if it is an ), then pop the stack
		3) if the stack is empty and there are more )'s, then return false
			else return true
		
		Ex. ["(())"]
		index 0 and 1 are pushed to the stack, then both are popped off when the char is )
		since the stack would be empty and the char vector is empty, the parenthesis are balanced
   */
	//convert the string to a char vector 
	std::vector<char> parens(str.begin(), str.end()); 
	Stack *stack = new Stack();	

	if (parens.size() == 0) {
		return true;
	}
	
	//loop through entire char vector
	for (int i = 0; i < (int) parens.size();i++) {
		//if current element is a (
		if (parens[i] == '(') {
			//push  the  char to the stack
			stack->push(parens[i]);
			continue;
		}
		//if current element is a )
		if (parens[i] == ')') {
			if (stack->isNOTEmptyOrFull()) {
				//pop the stack
				stack->pop();
				continue;
			} 

			return false;
		}
	}

	//if the stack still has parens in it return false
	if (stack->isNOTEmptyOrFull()) {
		return false;
	} else {
		return true;
	}
}

void outputResult(bool result) {
	if (result) {
		std::cout<<"The inputted string is balanced correctly\n";
	} else {
		std::cout<<"The inputted string is not balanced correctly\n";
	}
}

int main() {

	std::vector<std::string> tests;
	tests.push_back("(())");
	tests.push_back("((()");
	tests.push_back("()");
	tests.push_back("");
	tests.push_back(")(");
	tests.push_back("())()(");

	for (int i = 0; i < (int) tests.size(); i++) {
		outputResult(checkIfStringIsEqual(tests[i]));
	}

}
