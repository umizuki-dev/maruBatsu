#include <iostream>

enum Bit {
  Empty,
  Maru,
  Batsu
};

enum Turn {
  Sente,
  Gote
};

class Board {
  public:
    Bit bitBoard[3][3];
    Turn turn;

    Board() {
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          bitBoard[i][j] = Empty;
        }
      }
      turn = Sente;
    }
};

struct Move {
  int i;
  int j;
};

void clear() {
  for (int i = 0; i < 100; i++) {
    std::cout << "\n";
  }
}

void printBoard(Board board) {
  std::cout << "Turn: ";
  switch (board.turn) {
    case Sente:
      std::cout << "Sente";
      break;
    case Gote:
      std::cout << "Gote";
  }
  std::cout << "\n";

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      switch (board.bitBoard[i][j]) {
        case Empty:
          std::cout << "*";
          break;
        case Maru:
          std::cout << "O";
          break;
        case Batsu:
          std::cout << "X";
          break;
      }
    }
    /* must stack rows */
    std::cout << "\n";
  }
}

Move askMove() {
  Move move;

  std::cout << "Enter row: ";
  std::cin >> move.j;

  std::cout << "Enter column: ";
  std::cin >> move.i;

  return move;
}


int main() {
  Board gameBoard;

  clear();
  printBoard(gameBoard);


  return 0;
}
