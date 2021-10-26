//
// Created by cool8 on 29.09.2021.
//

#include "gtest/gtest.h"
#include "../src/Game.h"

TEST(GameCheckAlpha, checkAlpha) {
    Game game;
    char ourAlpha = 't';
    char ourDot = '.';
    ASSERT_EQ(game.checkAlpha('T', ourAlpha), false);
    ASSERT_EQ(game.checkAlpha('t', ourAlpha), true);
    ASSERT_EQ(game.checkAlpha('k', ourAlpha), false);
    ASSERT_EQ(game.checkAlpha('.', ourDot), true);
}

