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
#include <Object.h>
#include <Environment.h>

class Agent {
private:
	//std::list<Environment *> envs;

public:
	Agent();
	virtual ~Agent();

	virtual void see() {} // The agent takes sensory input from the environment.
	virtual void action() {} // The agent actions that affects the environment as output.

//	void regist_env(Environment* env) {
//		this->envs.push_back(env);
//	}
//
//	virtual void login(Environment* env) {
//		this->envs.push_back(env);
//	}

	virtual void logout() {
	}
};

#endif /* AGENT_H_ */
