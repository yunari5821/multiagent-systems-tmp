/*
 * utility.h
 *
 *  Created on: 2019/01/22
 *      Author: naritomi
 */

#ifndef SRC_COMMON_UTILITY_H_
#define SRC_COMMON_UTILITY_H_

#include <unistd.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class utility {
public:
	utility();
	virtual ~utility();

	/* カレントディレクトリ取得 */
	static string getCurrentDir() {
		char dir[1024];
		getcwd(dir,1024);
		string str(dir);
		return str;
	}


	/* 文字列スプリット */
	static std::vector<std::string> split(std::string str, char del) {
	    int first = 0;
	    int last = str.find_first_of(del);

	    std::vector<std::string> result;

	    while (first < str.size()) {
	        std::string subStr(str, first, last - first);

	        result.push_back(subStr);

	        first = last + 1;
	        last = str.find_first_of(del, first);

	        if (last == std::string::npos) {
	            last = str.size();
	        }
	    }

	    return result;
	}

};

#endif /* SRC_COMMON_UTILITY_H_ */
