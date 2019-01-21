/*
 * Environments.h
 *
 *  Created on: 2019/01/21
 *      Author: yusuke
 */

#ifndef ENVIRONMENTS_H_
#define ENVIRONMENTS_H_

#include <list>
#include <Environment.h>

#include "../agents/Agent.h"

class Environments {
	std::list<Environment *> envs;
	std::list<Agent *> agents;
public:
	Environments();
	virtual ~Environments();

	void register_env(Environment* env) {
		envs.push_back(env);
	}

	void register_agent(Agent* agent) {
		agents.push_back(agent);
	}
};

#endif /* ENVIRONMENTS_H_ */
