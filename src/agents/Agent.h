/*
 * Agent.h
 *
 *  Created on: 2019/01/18
 *      Author: yusuke
 */

#ifndef AGENT_H_
#define AGENT_H_

#include <string>

class Agent {
private:
	std::string name; // Agent name

public:
	Agent();
	virtual ~Agent();

	virtual void see() {} // The agent takes sensory input from the environment.
	virtual void action() {} // The agent actions that affects the environment as output.

};

#endif /* AGENT_H_ */
