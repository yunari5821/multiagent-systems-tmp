/*
 * main.cpp
 *
 *  Created on: 2019/01/18
 *      Author: yusuke
 */

#include <string>
#include <Environments.h>
#include <FxMarket.h>
#include <News.h>
#include <FxAgent.h>


int main(int argc, char *argv[]) {

	Environments envs;
	FxMarket fxmarket;
	News news("/Users/yusuke/git/multiagent-systems-tmp/src/main/simulation/FX/input/data.dat");
	FxAgent fxagent;

	envs.register_env(&fxmarket);
	envs.register_env(&news);

	envs.register_agent(&fxagent);

	while( true ) {
		break;
	}

	return 0;
}



