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

class News : Environment {
private:
	std::ifstream ifs;
	std::vector<int> importance;
public:
	News(std::string fname) : ifs(fname) {
		if ( this->ifs.fail() ) {
			throw "Exception : file open fales.";
		}
	}
	virtual ~News() {
		if(this->ifs.is_open()) ifs.close();
	}

	bool next() {
		this->importance.clear();
		if( !this->ifs.is_open() ) return false;
		if( this->ifs.eof() ) return false;
		std::string str;
		getline(this->ifs, str);
		return true;
	}
};

#endif /* NEWS_H_ */
