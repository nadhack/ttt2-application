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

#ifndef TTT_GAME_HPP
#define TTT_GAME_HPP

#include <ttt-board.hpp>


namespace ttt {

    class Game
    {
    public:

        Game(ttt::Player first_player = ttt::Player::CROSS);

        ttt::Board& board();

        const ttt::Board& board() const;

        ttt::Player current_player() const;

        ttt::Player toggle_player();

    private:

        ttt::Board m_board;
        ttt::Player m_player;
    };

} // namespace ttt

#endif // TTT_GAME_HPP
