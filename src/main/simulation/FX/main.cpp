/*
 * main.cpp
 *
 *  Created on: 2019/01/18
 *      Author: yusuke
 */

#include <string>
#include <list>
#include <Environments.h>
#include <FxMarket.h>
#include <News.h>
#include <FxAgent.h>
#include <tracelog.h>
#include <errorlog.h>
#include <utility.h>
#include "FxSimulationParameters.h"

using namespace std;

int main(int argc, char *argv[]) {

	/* Parameter Read */
	FxSimulationParameters param;
	param.init();
	if ( !param.readFile() ) {
		errorlog::error("File read failed.");
		return -1;
	}
	param.info();

	/* create world */
	Environments envs;

	/* create fxmarket and news */
	FxMarket fxmarket;
	fxmarket.setName("FxMarket");
	envs.register_env( &fxmarket );

	News news( param.getNewsFilePath() );
	news.setName("News");
	envs.register_env( &news );

	/* create agents */
	list< std::shared_ptr<FxAgent> > ages;
	for ( int i = 1; i <= param.getNumAgents(); i++ ) {

		/* create agent */
		std::shared_ptr<FxAgent> age( new FxAgent() );
		/* register agent to world */
		envs.register_agent( age.get() );

		/* name of agent */
		char buf[1024];
		sprintf(buf, "%d", i);
		string str(buf);
		string name( "Agent-" + str );
		age->setName( name );

		/* initilize importances */
		age->init_importances( i );

		/* list of envir onments that agent can join. */
		age->register_env( &fxmarket );
		age->register_env( &news );

		/* add agent */
		ages.push_back( age );

	}

//	FxAgent fxagent;
//
//
//
//	envs.register_agent(&fxagent);
//
//	news.next();
//	//news.next();
//
//	while( true ) {
//		break;
//	}
//
//	return 0;
}



