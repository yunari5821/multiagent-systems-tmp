/*
 * FxMarket.h
 *
 *  Created on: 2019/01/18
 *      Author: naritomi
 */

#ifndef SRC_ENVIRONMENT_MARKET_FXMARKET_H_
#define SRC_ENVIRONMENT_MARKET_FXMARKET_H_

#include <string>
#include <vector>
#include <map>
#include <RealFx.h>
#include "Market.h"

using namespace std;

class FxMarket : public Market {
private:
	RealFx realFx;
public:
	FxMarket();
	virtual ~FxMarket();
	void next() {
	}

	void readFxFile(const string& file, unsigned int start, unsigned int end) {

	}
};

#endif /* SRC_ENVIRONMENT_MARKET_FXMARKET_H_ */
