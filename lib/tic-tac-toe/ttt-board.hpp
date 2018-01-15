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

#ifndef TTT_BOARD_HPP
#define TTT_BOARD_HPP

#include <array>
#include <cstdint>
#include <iostream>
#include <vector>


namespace ttt {

    enum class Outcome
    {
        NONE,
        TIE,
        WIN_012,
        WIN_345,
        WIN_678,
        WIN_036,
        WIN_147,
        WIN_258,
        WIN_048,
        WIN_246
    };


    enum class Player:
        std::int8_t
    {
        NAUGHT = -1,
        NONE = 0,
        CROSS = 1
    };


    struct Result
    {
        ttt::Outcome outcome;
        ttt::Player player;

        Result(ttt::Outcome outcome, ttt::Player player):
            outcome(outcome),
            player(player)
        {}
    };


    class Board
    {
    public:

        Board();

        void clear();

        std::vector<int> available_moves() const;

        bool is_full() const;

        ttt::Result result() const;

        ttt::Player& operator[] (int i);

        const ttt::Player& operator[] (int i) const;

        void dump(std::ostream& os = std::cout);

    private:

        std::array<ttt::Player, 9> m_cells;
    };


    ttt::Player opponent(ttt::Player p);

    std::ostream& operator<< (std::ostream& os, Outcome o);

    std::ostream& operator<< (std::ostream& os, Player p);

} // namespace ttt

#endif // TTT_BOARD_HPP

