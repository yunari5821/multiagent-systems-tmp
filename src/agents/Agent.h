/*
 * Agent.h
 *
 *  Created on: 2019/01/18
 *      Author: yusuke
 */

#ifndef AGENT_H_
#define AGENT_H_

#include <string>
#include <list>
#include <Environment.h>

class Agent {
private:
	std::string name; // Agent name
	std::list<Environment *> access_envs; // accessible environments
	std::list<Environment *> login_envs; // currently login envs

public:
	Agent();
	virtual ~Agent();

	virtual void see() {} // The agent takes sensory input from the environment.
	virtual void action() {} // The agent actions that affects the environment as output.

	void register_env(Environment* env) {
		this->envs.push_back(env);
	}

	virtual void setName(const std::string& name ) {
		this->name = name;
	}

	virtual std::string getName() {
		return this->name;
	}


	virtual void login(Environment *env) {
		this->envs.push_back(env);
	}

	virtual void logout() {
	}
};

#endif /* AGENT_H_ */
