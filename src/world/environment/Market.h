/*
 * Market.h
 *
 *  Created on: 2019/01/18
 *      Author: naritomi
 */

#ifndef SRC_ENVIRONMENT_MARKET_MARKET_H_
#define SRC_ENVIRONMENT_MARKET_MARKET_H_

#include <list>
#include <Environment.h>
#include <Agent.h>

class Market : public Environment {
private:
	std::list<Agent *> agents; // pointer list of agent.
public:
	Market();
	virtual ~Market();

	virtual void register_agent(Agent *agent) {
		this->agents.push_back(agent);
	}

	virtual void next() = 0;
};

#endif /* SRC_ENVIRONMENT_MARKET_MARKET_H_ */
