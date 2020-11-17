#include <iostream> 

int main() {
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
    int arr[1000]; 
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
        void push(int value) {
            //if the top of the stack is greater than the space given 
            if (top_of_stack > 1000) {
                std::cout<<"Stack Overflow";
                return;
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

    };
}
