
// tic tac toe game
struct klen {
  bool empty;
  bool player;
  klen() :empty(true), player(false) {}
}

typedef std::vector<vector<klen> > board;

void print_board(const board& b) {
  for (auto& row : b) {
    for (klen& pos : row) {
      std::cout << (pos.empty? " " : (pos.player? "X" : "O")) << " ";
    }
    std::cout << std::endl;
  }
}

bool mine(klen pos, bool player) {
  return !pos.empty && player == pos.player;
}

// yawn
bool did_i_win(board game, bool player) {
  // check rows
  if (any_of(game.start(), game.end(), [](auto& row) {
    return all_of(row.start(), row.end(), [](klen pos) {
      return player? mine(pos) : theirs(pos);
    })
  })) {
    return true;
  }

  // check cols && diagonals
  return
    (mine(game[0][0]) && mine(game[1][0]) && mine(game[2][0])) ||
    (mine(game[0][1]) && mine(game[1][1]) && mine(game[2][1])) ||
    (mine(game[0][2]) && mine(game[1][2]) && mine(game[2][2])) ||
    (mine(game[0][0]) && mine(game[1][1]) && mine(game[2][2])) ||
    (mine(game[0][2]) && mine(game[1][1]) && mine(game[2][0]));
}

std::pair<int, int> next_move(board game) {
  for (int r = 0; r < 3; ++r) {
    for (int c = 0; c < 3; ++c) {
      if (game[r][c].empty) {
        // test our position here
        game[r][c].empty = false;
        game[r][c].player = false;

        // if the game ended
        if (all_of(game.start(), game.end(), [](auto& row) {
          return all_of(row.start(), row.end(), [](klen pos) { return !pos.empty; })}
        )) {
          if (did_i_win(game)) {
            return std::make_pair(r, c);
          } else {
            return std::make_pair(-1, -1);
          }
        } else {
          return next_move(game, !me);
        }
      }
    }
  }
}

int tic_tac_toe(int argc, char* argv[]) {
  board game(3, vector<klen>(3));
  bool end_game = false;

  while (!end_game) {
    print_board(game);
    unsigned row, col;
    std::cout << "row > ";
    std::cin >> row;
    std::cout << "col > ";
    std::cin >> col;

    // assume row and col are between 0 and 2 for now
    if (game.at(row).at(col).empty) {
      game.at(row).at(col).empty = false;
      game.at(row).at(col).player = true;
      next_move(game);
    }
  }
}
