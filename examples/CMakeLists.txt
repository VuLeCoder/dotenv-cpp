add_executable(dotenv-example
    basic.cpp
)

target_link_libraries(dotenv-example
    PRIVATE
        dotenv::dotenv
)
