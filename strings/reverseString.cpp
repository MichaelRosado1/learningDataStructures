#include <iostream>
#include <string>

std::string reverseString (std::string str) {
	std::string word = str;
	int i, j;
	i = 0;
	j = word.size() - 1;

	while (i < j) {
		char temp = word[i]; 
		word[i] = word[j];
		word[j] = temp; 
		i++;
		j--;
	}
	return word;
}

int main() {
	std::string otherWord = "MichaelR";
	std::string word = "hello";

	std::cout<<word<<" backwards is: "<<reverseString(word)<<std::endl;
	std::cout<<otherWord<<" backwards is: "<<reverseString(otherWord)<<std::endl;
}
