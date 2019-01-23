/*
 * Environment.h
 *
 *  Created on: 2019/01/18
 *      Author: naritomi
 */

#ifndef SRC_WORLD_ENVIRONMENT_H_
#define SRC_WORLD_ENVIRONMENT_H_

#include <string>
#include <list>
#include <Object.h>
#include <Agent.h>

class Environment : Object {
private:
	Agent agent;
	std::list<Agent *> agents;
public:
	Environment();
	virtual ~Environment();

	void regist_agent(Agent* agent) {
		this->agents.push_back( agent );
	}
};

#endif /* SRC_WORLD_ENVIRONMENT_H_ */
