## This may become a library at some point.
## For now, this will act as a listen server to act on the factorio process.
project(frame-host-api)
set(FFH_API_NAME ${PROJECT_NAME} CACHE INTERNAL "FFH_API_NAME")

set(FFHA_PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/private/main.cpp
)
set(FFHA_PUBLIC
    
)

set(FFHA_COLLECTIVE
    ${FFHA_PRIVATE}
    ${FFHA_PUBLIC}
)

add_executable(${PROJECT_NAME}
    ${FFHA_COLLECTIVE}
)

add_source_group(${FFHA_COLLECTIVE})

target_link_libraries(${PROJECT_NAME}
    ${FFH_NAME}
    ${UTILITIES}
)
