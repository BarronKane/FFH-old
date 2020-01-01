#include <iostream>
#include <string>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/program_options.hpp>

#include "logger.hpp"

#include "factorio-frame-host.h"

namespace opt = boost::program_options;

int main(int argc, char *argv[])
{
	boost::asio::io_context io_context;
	utilities::logger logger(io_context, "Server");
	logger.use_file("log.txt");
	

	opt::options_description desc("All options");

	desc.add_options()
		("dir,d", opt::value<std::string>(), "Factorio install directory.")
		("help,h", "CLI help information.");

	opt::variables_map vm;
	opt::store(opt::parse_command_line(argc, argv, desc), vm);
	opt::notify(vm);

	if (vm.count("help"))
	{
		std::cout << desc << "\n";
		logger.log("Printing help...");

		return 1;
	}

	if (vm.count("dir"))
	{
		std::cout << "Selected dir: " << vm["dir"].as<std::string>() << std::endl;
	}

	return 0;
}