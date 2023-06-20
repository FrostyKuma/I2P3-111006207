#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for random policy,
 * your policy class should have get_move method
 */
class MiniMax{
public:
  static int minimax_func(State *state, int depth, bool maxPlayer);
};
