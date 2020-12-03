#include <iostream> 

void checkIfPal(char word[], int start, int end) {
	if (start == end) {
		std::cout<<"It is a palindrome";
	}

	if (word[start] != word[end]) {
		std::cout<<"Not a palindrome";
	}
	if (start < end + 1) {
		checkIfPal(word, start + 1, end -1);
	}
}

int main() {

	char word[] = "tacocat";
	checkIfPal(word, 0, 6);
}
