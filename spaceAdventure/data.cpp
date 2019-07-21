#include "data.h"

std:string get_file_data(std::string fileName){
	std::fstream r_file;
	std::string file_read;
	r_file.open(fileName);

	getline(r_file, file_read);
	r_file.close();
	return file_read;
}
void save_log(){}
void open_log(){}
void remove_log(){}
