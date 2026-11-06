foreach(app demo_fraction demo_expression)
    add_executable(${app} ${app}.срр)
    target_link_libraries(${app} PRIVATE ratexpr)
endforeach()