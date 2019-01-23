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
#include <tracelog.h>

const int NUM_IMPORTANCE = 14;

class News : public Environment {
private:
	std::ifstream ifs;
	std::vector<int> importance;
public:
	News(const std::string fname) : ifs(fname) {
		if ( this->ifs.fail() ) {
			std::cerr << "Not foud a news file" << std::endl;
			throw "Exception : file open fales.";
		} else {
			tracelog::tag("Read news file");
			tracelog::keyvalue("news file", fname);
		}
	}
	virtual ~News() {
		if(this->ifs.is_open()) ifs.close();
	}

	void next() {
		if( !this->ifs.is_open() ) return;
		if( this->ifs.eof() ) return;

		std::string str;
		getline(this->ifs, str);

		std::vector<std::string> strs = utility::split(str, '\t');

		std::cout << strs.size() << std::endl;

		for ( int i = 0; i < strs.size(); i++ ) {
			this->importance.push_back( atoi( strs[ i ].c_str() ) );
		}

		this->importance.clear();
	}
};

#endif /* NEWS_H_ */
