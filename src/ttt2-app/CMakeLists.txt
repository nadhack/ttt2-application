set(ttt2-app_SOURCES
        main.cpp
)


add_executable(ttt2-app ${ttt2-app_SOURCES})

target_link_libraries(ttt2-app
        ttt
)
