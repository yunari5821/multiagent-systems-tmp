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
#include <errorlog.h>

class News : public Environment {
private:
	static const unsigned int NUM_IMPORTANCE;
	std::ifstream ifs;
	std::vector<int> importance;

public:
	News(const std::string fname) : ifs(fname) {
		if ( this->ifs.fail() ) {
			errorlog::error("Not found a news file");
			throw "Exception : Not found a news file";
		} else {
			tracelog::tag("Read news file");
			tracelog::keyvalue("news file", fname);
		}
		if( !this->ifs.is_open() ) {
			errorlog::error("File cannot open.");
		}
		if( this->ifs.eof() ) {
			errorlog::error("File is empty.");
			throw "Exception : File is empty.";
		}
		this->readline();
	}
	virtual ~News() {
		if(this->ifs.is_open()) ifs.close();
	}

	void readline() {
		std::string str;
		getline(this->ifs, str);
		std::vector<std::string> strs = utility::split(str, '\t');
		this->importance.clear();
		for ( int i = 0; i < strs.size(); i++ ) {
			this->importance.push_back( atoi( strs[ i ].c_str() ) );
		}
		if ( this->importance.size() != NUM_IMPORTANCE ) {
			errorlog::error("invalid importance.");
			throw "Exception : invalid importance.";
		}
	}

	void next() {
		if( this->ifs.eof() ) return;
		this->readline();
	}

	/* getter */
	std::vector<int> getImportance() {
		return this->importance;
	}
};

#endif /* NEWS_H_ */
