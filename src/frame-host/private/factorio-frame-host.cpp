#include <iostream>
#include <string>

#include <boost/chrono.hpp>

#include "factorio-frame-host.h"

namespace factorio
{

server::server()
{
}

void server::launch()
{
	// this->factorio_process::launch();
}

void server::add_arg(std::string name, std::string arg, std::string value)
{
	_arguments.push_back(std::make_tuple(name, arg, value));
}



} // namespace factorio
