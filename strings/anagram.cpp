#include <iostream> 
#include <string>

bool isAnagram(std::string word, std::string wordToCheck) {
	if (word.size() != wordToCheck.size()) return false; 

	int indexOfWord, indexOfComparisonWord;
	indexOfWord = 0;
	indexOfComparisonWord = 0;

	//for the length of the word
	while (indexOfWord < (int) word.size()) {
		//if the character is not found in the word
		if (indexOfComparisonWord == (int) word.size()) {
			//return false since character was not found
			return false;
		}
		if (word[indexOfWord] == wordToCheck[indexOfComparisonWord]) {
			indexOfWord++;
			indexOfComparisonWord = 0;
		} else {
			indexOfComparisonWord++;
		}	
	}
	return true;
}	

int main() {
	std::string word = "listen";
	std::string anagram = "silent";

	std::string word2 = "elvis";
	std::string anagram2 = "lives";
	std::string anagram3 = "livin";
	std::cout<<"is "<<anagram<<" an anagram of: "<<word<<" -> "<<isAnagram(word, anagram)<<std::endl;
	std::cout<<"is "<<anagram2<<" an anagram of: "<<word2<<" -> "<<isAnagram(word2, anagram2)<<std::endl;
	std::cout<<"is "<<anagram3<<" an anagram of: "<<word2<<" -> "<<isAnagram(word2, anagram3)<<std::endl;
}

