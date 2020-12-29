#include <iostream> 

int valid (char *username) {
	//search through characters until null character
	for (int i = 0; username[i] != '\0'; i++) {
		//checks if the current character is not a special character
		if (!(username[i] >= 65 && username[i] <= 90)) {
			if (!(username[i] >= 97 && username[i] <= 122)) {
				if (!(username[i] >= 48 && username[i] <= 57)) {
					return 0;
				}
			}
		}
	}
	//returns 1 if the string contains all valid characters 
	return 1;
}
int main() {
	char *username = "d1k312$$"; 
	std::cout<<valid(username)<<std::endl;;

	char *goodUsername = "mike123";
	std::cout<<valid(goodUsername)<<std::endl;
}
