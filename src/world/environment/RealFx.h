/*
 * RealFx.h
 *
 *  Created on: 2019/01/28
 *      Author: naritomi
 */

#ifndef SRC_WORLD_ENVIRONMENT_REALFX_H_
#define SRC_WORLD_ENVIRONMENT_REALFX_H_

#include <vector>
#include <string>

using namespace std;

class RealFx {
	vector<int> week;
	vector<string> date;
	vector<double> dollyen;
	vector<double> logrtn;
public:
	RealFx();
	virtual ~RealFx();
};

#endif /* SRC_WORLD_ENVIRONMENT_REALFX_H_ */
