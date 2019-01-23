/*
 * FxAgent.h
 *
 *  Created on: 2019/01/18
 *      Author: naritomi
 */

#ifndef SRC_AGENTS_FXAGENT_H_
#define SRC_AGENTS_FXAGENT_H_


#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <functional>
#include <math.h>
#include <Environment.h>
#include <Agent.h>

const int NUM_VARIABLE = 17;

class FxAgent : public Agent {
private:
	int x[NUM_VARIABLE]; // characteristic value
	int w[NUM_VARIABLE]; // importance of an agnet
	std::list<Environment *> envs; // environments
	double alpha; // scale factor
	double exlogrtn; // expectation of logarithmic return
	double var; // variance of logarithmic return
public:
	FxAgent();
	virtual ~FxAgent();

	/* get information from the environments. */
	void see() {
	}

	void action() {
	}

	/* initialization of importances by random number */
	void init_importances( int seed ) {
		std::mt19937 rand_src(seed);
		std::uniform_int_distribution<int> rand_dist(-3, 3); // w = [ -3, 3 ]
		for ( int i = 0; i < NUM_VARIABLE; i++ ) {
			this->w[ i ] = rand_dist( rand_src );
		}
	}

	void predict() {
		this->exlogrtn = this->calcExLogRtn();
	}

	double calcExLogRtn() {
		double exlogrtn = 0.0;
		for ( int i = 0; i < NUM_VARIABLE; i++ ) {
			exlogrtn += this->x[ i ] * this->w[ i ];
		}
		exlogrtn *= this->alpha;
		return floor(exlogrtn) * this->alpha;
	}

	void login(Environment *env) {
		this->envs.push_back(env);
	}

	void logout() {
	}
};

#endif /* SRC_AGENTS_FXAGENT_H_ */
