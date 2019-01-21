/*
 * FxMarket.h
 *
 *  Created on: 2019/01/18
 *      Author: naritomi
 */

#ifndef SRC_ENVIRONMENT_MARKET_FXMARKET_H_
#define SRC_ENVIRONMENT_MARKET_FXMARKET_H_

#include "Market.h"

class FxMarket : public Market {
public:
	FxMarket();
	virtual ~FxMarket();
	bool next() {
		return true;
	}
	void run() {
	}
};

#endif /* SRC_ENVIRONMENT_MARKET_FXMARKET_H_ */
