#pragma once

#include "logger_helpers.hpp"
#include "asio_logger.hpp"
#include "logger_service.hpp"

namespace utilities
{
namespace logging
{

// Typedef for typical logger usage.
typedef asio_logger<logger_service> logger;

} // namespace logging
} // namespace utilities
