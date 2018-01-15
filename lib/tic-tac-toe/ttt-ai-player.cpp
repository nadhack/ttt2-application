/*
 * MIT License
 *
 * Copyright (c) 2018 Matthew T. Bucknall
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <algorithm>
#include <random>

#include "ttt-ai-player.hpp"

using namespace ttt;


AiPlayer::AiPlayer(bool randomize, unsigned int depth):
    m_randomized(randomize),
    m_max_depth(depth)
{}


int AiPlayer::negamax(ttt::Game& game, int depth)
{
    if ( depth == 0 ) return 0;

    auto& board = game.board();
    auto result = board.result();

    if ( result.outcome == Outcome::TIE ) return 0;

    if ( result.outcome != Outcome::NONE )
    {
        if ( result.player == game.current_player() ) return depth;
        else return -depth;
    }

    if ( board.is_full() ) return 0;

    int best_score = std::numeric_limits<int>::lowest();

    for (int move = 0; move < 9; move++)
    {
        int score;

        if ( board[move] != Player::NONE ) continue;

        board[move] = game.current_player();
        game.toggle_player();

        score = -negamax(game, depth - 1);

        board[move] = Player::NONE;
        game.toggle_player();

        if ( score > best_score ) best_score = score;
    }

    return best_score;
}


int AiPlayer::find_best_move(ttt::Game& game) const
{
    auto& board = game.board();
    auto moves = board.available_moves();
    int best_move = -1;
    int best_score = std::numeric_limits<int>::lowest();

    if ( m_randomized )
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());

        std::shuffle(moves.begin(), moves.end(), gen);
    }

    for (auto move: moves)
    {
        int score;

        board[move] = game.current_player();
        game.toggle_player();

        score = -negamax(
            game,
            m_max_depth
        );

        board[move] = Player::NONE;
        game.toggle_player();

        if ( score > best_score )
        {
            best_score = score;
            best_move = move;
        }
    }

    return best_move;
}
