project(ffh-server)

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
    ${CMAKE_PROJECT_NAME}
)
