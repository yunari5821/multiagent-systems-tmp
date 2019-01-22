/*
 * FxSimulationParameters.h
 *
 *  Created on: 2019/01/22
 *      Author: yusuke
 */

#ifndef FXSIMULATIONPARAMETERS_H_
#define FXSIMULATIONPARAMETERS_H_

#include <iostream>
#include <fstream>
#include <string>

const int NUM_FX_PARAMS = 18;

class FxSimulationParameters {
private:
	double scale_factor; // 1
	int predict_step; // 2
	double min_band_lweeks; // 3
	double min_band; // 4
	double min_band_five_weeks; // 5
	int num_agents; // 6
	int train_start_line; // 7
	int predict_term_line; // 8
	int train_term_length; // 9
	double prob_cross;
	double prob_mutation;
	double prob_gap;
	int sim_iter;
	int train_iter;
	std::string output_type;
public:
	FxSimulationParameters();
	virtual ~FxSimulationParameters();

	bool readParametersFile(const std::string& fname) {
		std::ifstream ifs;
		if ( ifs.fail() ) {
			std::cerr << "Not foud a parameter file" << std::endl;
			throw "Exception : file open fales.";
		} else {
			std::cout << "Find a parameter file: " << fname << std::endl;
		}
		if( !ifs.is_open() ) return false;
		if( ifs.eof() ) return false;

		std::string str;
		for ( int i = 0; i < NUM_FX_PARAMS; i++ ) {
			getline(ifs, str);
			this->importance.push_back( atoi( strs[ i ].c_str() ) );
		}
		this->importance.clear();
	}
};

#endif /* FXSIMULATIONPARAMETERS_H_ */
