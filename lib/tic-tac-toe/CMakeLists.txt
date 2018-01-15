set(ttt_SOURCES
        ttt-ai-player.cpp
        ttt-board.cpp
        ttt-game.cpp
)

add_library(ttt STATIC ${ttt_SOURCES})
