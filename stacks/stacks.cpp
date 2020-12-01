#include <string>
#include <iostream> 
    /*
        Stacks are a last in first out structure meaning that the
        last inputted value is the first that will be removed.
            
        -only the top of the stack can be viewed
        -stacks are linear
        -can be used to balance symbols or work with equations
            

        -Can be implemented with a linked list or an array
        
   */

struct Stack {
    //the value of the most recent added value
int top_of_stack;
char arr[1000]; 
Stack() {
        top_of_stack = -1;
   } 

   //if the top fo the stack is -1, that means it has no values
    bool is_stack_empty() {
        if (top_of_stack < 0) {
            return true;

        }
        return false;
   } 
    
    void push(char value) {
      
        //if the top of the stack is greater than the space given 
        if (top_of_stack > 1000) {
            std::cout<<"Stack Overflow";
        }
        //++ before adds 1 to top_of_stack before setting the array at that index to 
        // the inputted value
        arr[++top_of_stack] = value;
        std::cout<<value<<" has been added to the stack!\n";


    }    

    void pop() {
        if (top_of_stack < 0) {
            std::cout<<"Stack Underflow";
        }
    }

    int top_value() {
        if (top_of_stack < 0) {
            std::cout<<"The stack is empty\n";
            return 0;
        }            //after an element is pushed, the top_of_stack variable is incremented
            //to get the last element, you need to get the previous index
            return arr[top_of_stack--];
    }
};
struct Stack *stack;
void addCharsToStack(std::string input) {
   for (int i = 0; i < sizeof(input) - 1; i++) {
      stack->push(input[i]);
   } 
   std::cout<<"top of stack is equal to: "<<stack->top_value();
}
std::string getUserInput() {
    std::cout<<"enter in string: ";
    std::string toReturn;
    std::cin>>toReturn;
    return toReturn;
}

int main() {

} 
