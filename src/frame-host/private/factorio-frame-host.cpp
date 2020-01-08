#include <iostream>
#include <string>

#include <boost/chrono.hpp>

#include "factorio-frame-host.h"

namespace factorio
{

server::server()
{
	init();
}

void server::init()
{
	build_args();
}

void server::build_args()
{
	m_args->bind = "0.0.0.0";
	m_args->port = "34197";

	m_args->arguments.push_back(std::make_pair("--bind", m_args->bind));
	m_args->arguments.push_back(std::make_pair("--port", m_args->port));
}


} // namespace factorio
