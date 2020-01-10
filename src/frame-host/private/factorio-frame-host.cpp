#include <iostream>
#include <string>

#include <boost/chrono.hpp>

#include "factorio-frame-host.h"

namespace factorio
{

server::server()
{
}

void server::init(factorio_args& args)
{
	build_args();
}

void server::launch()
{
	// this->factorio_process::launch();
}

/*
void server::build_args()
{

}
*/


} // namespace factorio
