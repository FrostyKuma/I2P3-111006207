#include <iostream>
#include <fstream>

#include "../config.hpp"
#include "../state/state.hpp"
#include "../policy/minimax.hpp"


State* root;

/**
 * @brief Read the board from the file
 *
 * @param fin
 */
void read_board(std::ifstream& fin) {
  Board board;
  int player;
  fin >> player;

  for (int pl=0; pl<2; pl++) {
    for (int i=0; i<BOARD_H; i++) {
      for (int j=0; j<BOARD_W; j++) {
        int c; fin >> c;
        // std::cout << c << " ";
        board.board[pl][i][j] = c;
      }
      // std::cout << std::endl;
    }
  }
  root = new State(board, player);
  root->get_legal_actions();
}


/**
 * @brief randomly choose a move and then write it into output file
 *
 * @param fout
 */
void write_valid_spot(std::ofstream& fout) {
  if(!root->legal_actions.size())
    root->get_legal_actions();
  // Keep updating the output until getting killed.
  int end_val, max_val = -12938694; //ALPHA ITU ANGKA TERKECIL, YG -INF && BETA ITU ANGKA TERBESAR YG +INF
  //TAMBAHIN ALPHA BETA DISINI BUAT BIKIN YG ALPHA BETA
  Move move;
  for(auto& con : root->legal_actions){
    end_val = MiniMax::minimax_func(root->next_state(con), 4, false);
    if(end_val > max_val){
        max_val = end_val;
        move = con;
    }
    // Choose a random spot.
    if(move.first == move.second){
        move = root->legal_actions[0];
    }
    fout << move.first.first << " " << move.first.second << " "\
         << move.second.first << " " << move.second.second << std::endl;

    // Remember to flush the output to ensure the last action is written to file.
    fout.flush();
  }
}


/**
 * @brief Main function for player
 *
 * @param argv
 * @return int
 */
int main(int, char** argv) {
  srand(RANDOM_SEED);
  std::ifstream fin(argv[1]);
  std::ofstream fout(argv[2]);

  read_board(fin);
  write_valid_spot(fout);

  fin.close();
  fout.close();
  return 0;
}
