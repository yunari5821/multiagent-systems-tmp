/*
 * News.h
 *
 *  Created on: 2019/01/18
 *      Author: yusuke
 */

#ifndef NEWS_H_
#define NEWS_H_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <Environment.h>
#include <utility.h>

const int NUM_IMPORTANCE = 14;

class News : public Environment {
private:
	std::ifstream ifs;
	std::vector<int> importance;
public:
	News(const std::string fname) : ifs(fname) {
		if ( this->ifs.fail() ) {
			throw "Exception : file open fales.";
		} else {
			std::cout << "Find a news file: " << fname << std::endl;
		}
	}
	virtual ~News() {
		if(this->ifs.is_open()) ifs.close();
	}

	bool next() {
		if( !this->ifs.is_open() ) return false;
		if( this->ifs.eof() ) return false;

		std::string str;
		getline(this->ifs, str);

		std::vector<std::string> strs = utility::split(str, ' ');

		std::cout << strs.size() << std::endl;

		for ( int i = 0; i < strs.size(); i++ ) {
			std::cout << strs[i] << std::endl;
		}

		this->importance.clear();

		return true;
	}
};

#endif /* NEWS_H_ */
