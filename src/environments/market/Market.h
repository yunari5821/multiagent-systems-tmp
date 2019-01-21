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
	std::list<Agent *> p_agnets; // Agent pointer list
public:
	Market();
	virtual ~Market();

	virtual void run() = 0;
};

#endif /* SRC_ENVIRONMENT_MARKET_MARKET_H_ */
