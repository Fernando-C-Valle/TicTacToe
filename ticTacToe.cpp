#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include <iomanip>

void showOptions(){
	std::cout << "The players must choose one of these positions, from 1 through 9" << std::endl;
	std::cout << "If the grid gets filled and there is no winner, then the result will be a DRAW" << std::endl;
	std::cout << "Have Fun!!!" << std::endl;
	int counter = 1;
	for(int i=1;i<=9;i++){
		if(counter == 3){
			std::cout << i << " | " << std::endl;
			counter = 0;
		}
		else {
			if(i == 1 || i == 4 || i == 7){
				std::cout << " | " << i << " | ";
			}
			else {
				std::cout << i << " | ";
			}
		}
		counter++;
	}
}

void showGrid(const std::vector< std::string > &grid){
	int counter = 1;
	for(int i=0;i<9;i++){
		if(counter == 3){
			std::cout << grid[i] << " | " << std::endl;
			counter = 0;
		}
		else {
			if(i % 3 == 0){
				std::cout << " | " << grid[i] << " | ";
			}
			else {
				std::cout << grid[i] << " | ";
			}
		}
		counter++;
	}
}

bool checkRows(const std::vector< std::string > &vec, std::string s){
	for(int i=0;i<9;i+=3){
		if(vec[i] == vec[i+1] && vec[i+1] == vec[i+2] && vec[i+2] == s){
			return true;
		}
	}
	return false;	
}

bool checkColumns(const std::vector< std::string > &vec, std::string s){
	for(int i=0;i<3;i++){
		if(vec[i] == vec[i+3] && vec[i+3] == vec[i+6] && vec[i+6] == s){
			return true;
		}
	}
	return false;
}

bool checkDiagonals(const std::vector< std::string > &vec, std::string s){	
	if(vec[0] == vec[4] && vec[4] == vec[8] && vec[8] == s){
		return true;
	} 
	else if(vec[2] == vec[4] && vec[4] == vec[6] && vec[6] == s){
		return true;
	}
	return false;
}



bool checkWin(const std::vector<std::string> &vec, std::string s){
	if(checkRows(vec, s) == true){ //Check rows
		return true;
	}
	else if(checkColumns(vec, s) == true){ //Check columns
		return true;
	}
	else if(checkDiagonals(vec, s) == true){ //Check diagonals
		return true;
	}	
	return false;
}


int main(){	
	int position = 0;
	int count = 2;
	bool flag = true;
	bool isNumberThere = false;
	bool winner = false;
	std::string symbol {"O"};
	std::string input {};
	std::string name1 {};
	std::string name2 {};
	std::string switchNames {};
	std::vector< int > positions(9,0);//Filled with nine 0's
	std::vector< std::string > grid (9, " ");	
	std::vector< std::string > positionsO (9," ");
	std::vector< std::string > positionsX (9," ");
	
	showOptions();
	
	//Game starts
	std::string s{"GAME STARTS"};
	std::cout << std::setw(10) << std::setfill('-') << "" << s << std::setw(10) << std::setfill('-') << "" << std::endl;
	std::cout << std::setfill('*') << std::endl;
	std::cout << "Player 1, please type your name: " << std::endl;
	std::cin >> name1;
	std::cout << "Player 2, please type your name: " << std::endl;
	std::cin >> name2;	
	switchNames = name1;
	
	while(flag != false){		
		do{
			std::cout << "Symbol: " << symbol << ", " << switchNames << ", type a valid position: " << std::endl;
			std::cin >> input;
			std::istringstream correctInput {input};//input string stream object for validation
			//If the input is correct
			if(correctInput >> position){
				if(position >= 1 && position <= 9){//If it is a valid grid number
					if(positions[position-1] == 0){//If the position is available
						positions[position-1] = position;
						isNumberThere = true;
					}
				}
			}
			//Discards the input buffer
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		}while(position < 1 || position > 9 || isNumberThere != true);
		
		grid[position-1] = symbol;
		
		if(symbol == "O"){
			positionsO[position-1] = "O";
		} else {
			positionsX[position-1] = "X";
		}
		
		//Check for wins only if one user has typed 3 or more times
		if(count > 5){
			if(count % 2 == 0){//Check O
				if(checkWin(positionsO, "O") == true){
					std::cout << " ----- " << name1 << " wins ----- " << std::endl;
					flag = false;
					winner = true;
				}
			}
			else {//Check X
				if(checkWin(positionsX, "X") == true){					
					std::cout << " ----- " << name2 << " wins ----- " << std::endl;
					flag = false;
					winner = true;
				}
			}
		}
		
		showGrid(grid);
		
		//Switch player
		if(count % 2 == 0){
			symbol = "X";
			switchNames = name2;
		} 
		else {
			symbol = "O";
			switchNames = name1;
		}
		
		//Check for draw
		if(count == 10 && winner != true){
			std::cout << " ==== DRAW ====" << std::endl;
			flag = false;
		}		
		count++;//Keep a count of the symbols placed
		isNumberThere = false;//Reset the flag so we can check again for the position
	}
	
	std::cout << "Thanks for playing!" << std::endl;
	
	return 0;
}
