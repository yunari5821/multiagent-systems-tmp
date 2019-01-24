/*
 * Environment.h
 *
 *  Created on: 2019/01/18
 *      Author: naritomi
 */

#ifndef SRC_WORLD_ENVIRONMENT_H_
#define SRC_WORLD_ENVIRONMENT_H_

class Agent;

#include <string>
#include <list>
#include <Object.h>

class Environment : public Object {
private:
	std::list<Agent *> agents;
public:
	Environment();
	virtual ~Environment();

	void regist(Agent* agent) {
		this->agents.push_back( agent );
	}
};

#endif /* SRC_WORLD_ENVIRONMENT_H_ */
