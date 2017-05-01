//============================================================================
// Name        : MyTest.cpp
// Author      : Ema
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include<string.h>


#define num_array 5
#define dim_array 6


char index[] = {"1-/-/-/-/"};
int index_dim = 9;

void addArray(int row, const char* array[], int dim){

	for(int i=0; i<dim; i++){
		menu_array[row][i] = array[i];
	}

	for(int i=dim-1; i<dim_array; i++){
		menu_array[row][i] = "nil";
	}
}

int getLength(char text[]){
	int dim = index_dim;
	int i=0;
	while(i<dim){
		if(text[i] == '/'){
			break;
		}else{
			i++;
		}
	}
	if(i == dim){
		i = dim;
	}else{
		i= i-1;
	}
	return i;
}

bool checkChartMatch(char index[], int row){
	int length = getLength(index);
	char temp[20];
	bool equal = true;
	for(int j=0; j<length; j++){
		strcpy(temp, menu_array[row][0]);
		if(temp[j] != index[j]){
			equal = false;
		}
	}
	return equal;
}


int getMenuRow(char index[]){
	int value;
	for(int i=0; i<num_array; i++){
		if(checkChartMatch(index,i) == true){
			value = i;
			break;
		}
	}
	return value;
}

void nextLevel(char num){
	int i = 0;
	while(i<index_dim){
		if(index[i] == '/'){
			break;
		}else{
			i++;
		}
	}

	if(i < index_dim){
		index[i] = num;
	}
}

void backLevel(){
	int i = 0;
	while(i<index_dim){
		if(index[i] == '/'){
			break;
		}else{
			i++;
		}
	}

	if(i == index_dim){
		index[i-1] = '/';
	}else{
		if(i < index_dim and i > 2){
			index[i-2] = '/';
		}
	}

}

int getSizeArray(int row){
	int i = 1;
	while(i < dim_array){
		const char* temp = menu_array[row][i];
		if(temp == "nil"){
			break;
		}else{
			i++;
		}
	}

	if(i < dim_array){
		i++;
	}
	return i;
}

int main() {
	const char* level_1[6] = {"1","Sensors", "RBG LED", "Erin", "Mani", "Doggy dog"};
	const char* level_1_1[4] {"1-1","Temperature", "Light", "<- BACK"};
	const char* level_1_1_1[4] {"1-1-1-2-4","ON", "OFF", "<- BACK"};
	const char* level_1_2[6] {"1-2","OFF", "Blue", "Green", "Red", "<- BACK"};
	const char* level_1_3[2] {"1-3","<- BACK"};
	const char* menu_array[num_array][dim_array];



	addArray(0, level_1, 6);
	addArray(1, level_1_1, 4);
	addArray(2, level_1_1_1, 4);
	addArray(3, level_1_2, 6);
	addArray(5, level_1_3, 2);

	char test2[] = {"1-1-1-2-4"};
	int num = 2;
	char num_char = '0' + num;
	nextLevel(num_char);
	nextLevel(num_char);
	nextLevel(num_char);
	nextLevel(num_char);
	backLevel();
	backLevel();
	backLevel();
	backLevel();
	backLevel();

//	int test = getMenuRow(test2);

//	int test = getSizeArray(8);

	const char* array[dim_array];
	for(int i = 1; i < dim_array; i++){
		array[i-1] = menu_array[0][i];
	}


//	int test = 0;
	cout << test2 << "\n" << array[0] << "\n" << array[0] << endl;
	return 0;
}
