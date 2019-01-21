/*
 * Environment.h
 *
 *  Created on: 2019/01/18
 *      Author: naritomi
 */

#ifndef SRC_ENVIRONMENT_ENVIRONMENT_H_
#define SRC_ENVIRONMENT_ENVIRONMENT_H_

class Environment {
public:
	Environment();
	virtual ~Environment();

	virtual bool next() = 0; // to proceed the time of the environment.
};

#endif /* SRC_ENVIRONMENT_ENVIRONMENT_H_ */
