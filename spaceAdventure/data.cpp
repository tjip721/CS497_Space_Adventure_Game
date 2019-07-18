#include data.h

std:string get_file_data(char *text){
	ifstream description_file(text);
	description_file >> file_holder;
	description_file.close();
	return file_holder;
}
void save_log(){}
void open_log(){}
void remove_log(){}