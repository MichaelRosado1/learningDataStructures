#include <iostream>
#include <string>

bool hasDuplicates(std::string word) {
	int i, j;
	i = 0;
	j = 1;

	while (i < (int) word.size() - 1) {
		if (j == (int) word.size()) {
			i++;
			j = i + 1;
		}
		if (word[i] == word[j] && i != j) {
			std::cout<<word[i]<<" "<<word[j]<<std::endl;
			return true;
		} else {
			j++;
		}
	}
	return false;
}

int main() {
	std::string word = "hello";
	std::string otherWord = "nope";
	std::string word3 = "argon";
	
	std::cout<<"does "<<word<<" contain any duplicate letters: "<<hasDuplicates(word)<<std::endl;
	std::cout<<"does "<<otherWord<<" contain any duplicate letters: "<<hasDuplicates(otherWord)<<std::endl;
	std::cout<<"does "<<word3<<" contain any duplicate letters: "<<hasDuplicates(word3)<<std::endl;
}
