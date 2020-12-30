#include <iostream> 

bool isPalnidrome(std::string word) {
	int startIndex, endIndex;
	startIndex = 0;
	endIndex = word.size() - 1;

	while (startIndex < endIndex) {
		if (word[startIndex] != word[endIndex]) {
			return false;
		} else {
			startIndex++;
			endIndex--;
		}
	}
	return true;	
}

int main() {
	std::string word = "tacocat";
	std::string str = "racecar";
	std::string otherWord = "Odie";

	std::cout<<"is "<<word<<" a palindrom: "<<isPalnidrome(word)<<std::endl;
	std::cout<<"is "<<str<<" a palindrom: "<<isPalnidrome(str)<<std::endl;
	std::cout<<"is "<<otherWord<<" a palindrom: "<<isPalnidrome(otherWord)<<std::endl;
}
