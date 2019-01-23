/*
 * Object.h
 *
 *  Created on: 2019/01/24
 *      Author: yusuke
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include <string>

class Object {
private:
	std::string name;
public:
	Object();
	virtual ~Object();

	// time development
	virtual void next() {
	}

	// getter
	virtual std::string getName() {
		return this->name;
	}

	// setter
	virtual void setName( const std::string& name ) {
		this->name = name;
	}
};

#endif /* OBJECT_H_ */
