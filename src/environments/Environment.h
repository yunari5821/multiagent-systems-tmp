/*
 * Environment.h
 *
 *  Created on: 2019/01/18
 *      Author: naritomi
 */

#ifndef SRC_ENVIRONMENT_ENVIRONMENT_H_
#define SRC_ENVIRONMENT_ENVIRONMENT_H_

#include <string>

class Environment {
private:
	std::string name;
public:
	Environment();
	virtual ~Environment();

	// to proceed the time of the environment.
	virtual bool next() {
		return true;
	}

	virtual void setName( const std::string& name ) {
		this->name = name;
	}
};

#endif /* SRC_ENVIRONMENT_ENVIRONMENT_H_ */
