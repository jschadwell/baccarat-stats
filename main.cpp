/*
 * baccarat-stats.cpp
 *
 *  Created on: Aug 26, 2016
 *      Author: jeff
 */

#include <iostream>
#include <iterator>
#include <boost/program_options.hpp>

using namespace std;
namespace po = boost::program_options;

int main(int argc, char* argv[])
{
	int cycles(0);
	int shuffles(0);

	try {
		po::options_description desc("Allowed options");
		desc.add_options()
			("help", "produce help message")
			("cycles,c", po::value<int>(&cycles)->required(), "number of times to cycle through a full shoe")
			("shuffles,s", po::value<int>(&shuffles)->required(), "number of shuffles to perform on each new shoe")
		;

		po::variables_map vm;
		po::store(po::parse_command_line(argc, argv, desc), vm);
		po::notify(vm);

		if (vm.count("help")) {
			cout << desc << endl;
			return 0;
		}
	}
	catch(exception& e) {
		cerr << "Error: " << e.what() << endl;
		return 1;
	}
	catch(...) {
		cerr << "Unknown error" << endl;
	}

	cout << "cycles = " << cycles << endl;
	cout << "shuffles = " << shuffles << endl;
}
