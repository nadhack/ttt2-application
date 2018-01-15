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
#include <cstddef>

#include "ttt-board.hpp"

using namespace ttt;


Board::Board()
{
    clear();
}


void Board::clear()
{
    std::fill(
        m_cells.begin(),
        m_cells.end(),
        Player::NONE
    );
}


std::vector<int> Board::available_moves() const
{
    std::vector<int> moves;

    for (std::size_t i = 0; i < m_cells.size(); ++i)
    {
        if ( m_cells[i] == Player::NONE ) moves.push_back(static_cast<int>(i));
    }

    return moves;
}


bool Board::is_full() const
{
    return std::find(m_cells.begin(), m_cells.end(), Player::NONE) == m_cells.end();
}


Result Board::result() const
{
    const auto& c = m_cells;

    if ( c[0] != Player::NONE && c[0] == c[1] && c[1] == c[2] )
        return Result(Outcome::WIN_012, c[0]);

    if ( c[3] != Player::NONE && c[3] == c[4] && c[4] == c[5] )
        return Result(Outcome::WIN_345, c[3]);

    if ( c[6] != Player::NONE && c[6] == c[7] && c[7] == c[8] )
        return Result(Outcome::WIN_678, c[6]);

    if ( c[0] != Player::NONE && c[0] == c[3] && c[3] == c[6] )
        return Result(Outcome::WIN_036, c[0]);

    if ( c[1] != Player::NONE && c[1] == c[4] && c[4] == c[7] )
        return Result(Outcome::WIN_147, c[1]);

    if ( c[2] != Player::NONE && c[2] == c[5] && c[5] == c[8] )
        return Result(Outcome::WIN_258, c[2]);

    if ( c[0] != Player::NONE && c[0] == c[4] && c[4] == c[8] )
        return Result(Outcome::WIN_048, c[0]);

    if ( c[2] != Player::NONE && c[2] == c[4] && c[4] == c[6] )
        return Result(Outcome::WIN_246, c[2]);

    if ( is_full() ) return Result(Outcome::TIE, Player::NONE);

    return Result(Outcome::NONE, Player::NONE);
}


Player& Board::operator[](int i)
{
    return m_cells[i];
}


const Player& Board::operator[](int i) const
{
    return m_cells[i];
}


void Board::dump(std::ostream& os)
{
    const auto& c = m_cells;

    os << ' ' << c[0] << " | " << c[1] << " | " << c[2] << std::endl;
    os << "---+---+---" << std::endl;
    os << ' ' << c[3] << " | " << c[4] << " | " << c[5] << std::endl;
    os << "---+---+---" << std::endl;
    os << ' ' << c[6] << " | " << c[7] << " | " << c[8] << std::endl;
}


ttt::Player ttt::opponent(ttt::Player p)
{
    return static_cast<ttt::Player>(static_cast<std::int8_t>(p) * -1);
}


std::ostream& ttt::operator<<(std::ostream& os, Outcome o)
{
    switch(o)
    {
    case Outcome::NONE:
        return os << "none";

    case Outcome::TIE:
        return os << "tie";

    case Outcome::WIN_012:
        return os << "win_012";

    case Outcome::WIN_345:
        return os << "win_345";

    case Outcome::WIN_678:
        return os << "win_678";

    case Outcome::WIN_036:
        return os << "win_036";

    case Outcome::WIN_147:
        return os << "win_147";

    case Outcome::WIN_258:
        return os << "win_258";

    case Outcome::WIN_048:
        return os << "win_048";

    case Outcome::WIN_246:
        return os << "win_246";
    }

    return os;
}


std::ostream& ttt::operator<< (std::ostream& os, Player p)
{
    switch(p)
    {
    case Player::NAUGHT:
        return os << 'O';
    case Player::NONE:
        return os << ' ';
    case Player::CROSS:
        return os << 'X';
    }

    return os;
}
