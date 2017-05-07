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


#define num_array 4
#define dim_array 5


char index[] = {"1-/-/-/-/"};
int index_dim = 9;

//Menu
char* level_1[3] = {"1","Sensors", "RBG LED"};
char* level_1_1[3] {"1-1","Temperature", "Light"};
char* level_1_1_1[3] {"1-1-1","ON", "OFF"};
char* level_1_1_2[3] {"1-1-2","ON", "OFF"};
char* level_1_2[5] {"1-2","Blue", "Green", "Red", "OFF"};
long current_ok_counter = 0;
long current_scroll_counter = 0;
long ok_counter = 0;
long scroll_counter = 0;
int ok_result = 0;
int scroll_result = 0;
int size_array = 0;

//used to get the correct array
int remainder = 0;
int menu_array_row = 0;


//menu_array to identify the correct array to show
char* menu_array[num_array][dim_array];

void addArray(int row, char* array[], int dim){

	for(int i=0; i<dim; i++){
		menu_array[row][i] = array[i];
	}

	for(int i=dim; i<dim_array; i++){
		menu_array[row][i] = "nil";
	}
}

int getLength(char text[]){
	int dim = index_dim;
	int i=0;
	while(i<dim){
		if(text[i] == '/'){
			if(i<dim){
				i -=1 ;
			}
			break;
		}
		if((text[i] == NULL) || (text[i] == '\0')){
			break;
		}else{
			i++;
		}
	}
	if(i > dim){
		i = dim;
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
	int length_index = getLength(index);
	bool found =  false;
	int value;
	for(int i=0; i<num_array && !found; i++){
		// compare length of index first and then if they are equal
		int length_menu_array_index = getLength(menu_array[i][0]);
		if(length_index == length_menu_array_index){
			char temp[length_index];
			int num_char =0;
			for(j=0; j<length_index; j++){
				strcpy(temp, menu_array[i][0]);
				if(temp[j] != index[j]){
					break;
				}else{
					num_char += 1;
				}
			}
			if(num_char == length_index){
				found = true;
			}
		}
		value = i;
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
	int i = 0;
	while(i < dim_array){
		char* temp = menu_array[menu_array_row][i];
		if(temp == "nil"){
			break;
		}else{
			i++;
		}
	}

	if(i < dim_array){
		i -= 1;
	}
	return i;
}

int main() {
	addArray(0, level_1, 3);
	addArray(1, level_1_1, 4);
	addArray(2, level_1_1_1, 4);
	addArray(3, level_1_1_2, 4);
	addArray(4, level_1_2, 6);

	char test_index[] = {"1-1-/-/-/"};
//	int num = 2;
//	char num_char = '0' + num;
//	nextLevel(num_char);
//	nextLevel(num_char);
//	nextLevel(num_char);
//	nextLevel(num_char);
//	backLevel();
//	backLevel();
//	backLevel();
//	backLevel();
//	backLevel();

	int row = getMenuRow(test_index);

	int size = getSizeArray(row);

	const char* array[size];
	for(int i = 0; i < (size); i++){
		array[i] = menu_array[row][i+1];
	}

	cout << row << "\n" << size << "\n" << array[0] << "\n" << array[1] << "\n" << array[2] << endl;
	return 0;
}
