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

#include <iostream>

#include <ttt-ai-player.hpp>
#include <ttt-game.hpp>


int main(int argc, char* argv[])
{
    ttt::Game g;
    ttt::AiPlayer ai(true, 20);

    for (;;)
    {
        auto& b = g.board();

        int move = ai.find_best_move(g);

        b[move] = g.current_player();

        auto result = b.result();

        if ( result.outcome != ttt::Outcome::NONE )
        {
            b.dump();
            std::cout << result.outcome << ", '" << result.player << "'" << std::endl << std::endl;

            b.clear();
            if ( result.outcome != ttt::Outcome::TIE ) break;
        }

        g.toggle_player();
    }

    return 0;
}
