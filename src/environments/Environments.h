/*
 * Environments.h
 *
 *  Created on: 2019/01/21
 *      Author: yusuke
 */

#ifndef ENVIRONMENTS_H_
#define ENVIRONMENTS_H_

#include <iostream>
#include <list>
#include <Environment.h>

#include "../agents/Agent.h"

class Environments {
private:
	std::list<Environment *> envs;
	std::list<Agent *> agents;
public:
	Environments();
	virtual ~Environments();

	void register_env(Environment* env) {
		this->envs.push_back(env);
	}

	void register_agent(Agent* agent) {
		this->agents.push_back(agent);
	}

	void output_agents_name() {
		std::list<Agent *>::iterator itr;
		for (itr = this->agents.begin(); itr != this->agents.end(); itr++) {
			Agent *p_agent = *itr;
			std::cout << p_agent->getName() << std::endl;
		}
	}

	void run() {
		this->output_agents_name();
		std::list<Environment *>::iterator itr;
		for (itr = envs.begin(); itr != envs.end(); itr++) {
			//std::cout << *itr << std::endl;
		}
	}
};

#endif /* ENVIRONMENTS_H_ */
