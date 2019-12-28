## This may become a library at some point.
## For now, this will act as a listen server to act on the factorio process.
project(frame-host-api)
set(FFH_API_NAME ${PROJECT_NAME} CACHE INTERNAL "FFH_API_NAME")

set(FFH_PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/private/main.cpp
)
set(FFH_PUBLIC
    
)

add_executable(${PROJECT_NAME}
    ${FFH_PRIVATE}
    ${FFH_PUBLIC}
)

target_link_libraries(${PROJECT_NAME}
    ${FFH_NAME}
)
