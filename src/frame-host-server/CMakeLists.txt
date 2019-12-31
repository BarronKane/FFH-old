project(frame-host-server)
set(FFH_SERVER ${PROJECT_NAME} CACHE INTERNAL "FFH_SERVER")

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
    ${FFH_API}
    ${UTILITIES}
)
