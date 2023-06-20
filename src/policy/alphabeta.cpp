#include <cstdlib>

#include "../state/state.hpp"
#include "./alphabeta.hpp"

int AlphaBeta::alphabeta_func(State *state, int depth, int alpha, int beta, bool maxPlayer){
    //FUNCTIONNYA TAMBAHIN ALPHA BETA DI PARAMETERNNYA DGN IKUTIN PSEUDOCODENYA
     if(depth == 0){
        if(maxPlayer){
            return state->evaluate();
        }
        else{
            State *cont_state = new State(state->board, 1-(state->player));
            return cont_state->evaluate();
        }
     }
     if(state->game_state == WIN){
        if(maxPlayer){
            return state->evaluate() + 10000;
        }
        else{
            State *cont_state = new State(state->board, 1-(state->player));
            return cont_state->evaluate() - 10000;
        }
     }

     if(maxPlayer){
        int max_val = -121314252;
        for(auto& Move : state->legal_actions){
            State *temp = state->next_state(Move);
            max_val = std::max(max_val, alphabeta_func(temp, depth-1, alpha, beta, false));
            alpha = std::max(alpha, max_val);
            if(alpha >= beta){
                break;
            }
        }
        return max_val;
     }
     else{
        int min_val = 121314252;
        for(auto& Move : state->legal_actions){
            State *temp = state->next_state(Move);
            min_val = std::min(min_val, alphabeta_func(temp, depth-1, alpha, beta, true));
            beta = std::min(beta, min_val);
            if(beta <= alpha){
                break;
            }
        }
        return min_val;
     }
}
