#include <cstdlib>

#include "../state/state.hpp"
#include "./minimax.hpp"

int MiniMax::minimax_func(State *state, int depth, bool maxPlayer){
    //FUNCTIONNYA TAMBAHIN ALPHA BETA DI PARAMETERNNYA DGN IKUTIN PSEUDOCODENYA
     if(depth == 0){
        return state->evaluate();
     }
     if(maxPlayer){
        int max_val = -121314252;
        for(auto& Move : state->legal_actions){
            State *temp = state->next_state(Move);
            max_val = std::max(max_val, minimax_func(temp, depth-1, false));
        }
        return max_val;
     }
     else{
        int min_val = 121314252;
        for(auto& Move : state->legal_actions){
            State *temp = state->next_state(Move);
            min_val = std::min(min_val, minimax_func(temp, depth-1, true));
        }
        return min_val;
     }
}
