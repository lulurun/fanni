/*
 * FileUtils.h
 *
 *  Created on: Aug 29, 2009
 *      Author: lulu
 */

#ifndef FILEUTILS_H_
#define FILEUTILS_H_

#include <string>
#include <fstream>

namespace Fanni {

class FileUtils {
public:
	static size_t get_file_size(const std::string &file_path) {
		size_t file_size = 0;
		ifstream fs(file_path.c_str());
		if(fs.fail()) {
			ERROR_LOG("can not open file: " << file_path);
			return 0;
		}
		fs.seekg(0, ios::end); //move to end of file
		file_size = fs.tellg();
		return file_size;
	};

	static std::string get_file_name(const string& file_path) {
	#ifdef _WIN32
	   char sep = '\\';
	#else
	   char sep = '/';
	#endif
	   size_t i = file_path.rfind(sep, file_path.length( ));
	   if (i != string::npos) {
		  return(file_path.substr(i+1, file_path.length( ) - i));
	   }
	   return("");
	};

};

}

#endif /* FILEUTILS_H_ */
