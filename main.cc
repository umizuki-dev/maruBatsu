#include <iostream>

enum Bit {
  Empty, Maru, Batsu
};

enum Turn {
  Sente,
  Gote
};

struct Move {
  int i;
  int j;
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

    void switchTurn() {
      if (turn == Sente) {
        turn = Gote;
      } else {
        turn = Sente;
      }
    }
};

void clear() {
  for (int i = 0; i < 100; i++) {
    std::cout << "\n";
  }
}

void printBoard(Board board) {
  std::cout << "手番：";
  switch (board.turn) {
    case Sente:
      std::cout << "先手";
      break;
    case Gote:
      std::cout << "後手";
  }

  std::cout << "\n＝＝＝＝＝\n\n";

  /* column numbers for moves */
  std::cout << "　　１２３\n";
  std::cout << "　　ーーー\n";

  for (int i = 0; i < 3; i++) {
    switch (i) {
      case 0:
        std::cout << "１｜";
        break;
      case 1:
        std::cout << "２｜";
        break;
      case 2:
        std::cout << "３｜";
        break;
    }

    for (int j = 0; j < 3; j++) {
      switch (board.bitBoard[i][j]) {
        case Empty:
          std::cout << "＊";
          break;
        case Maru:
          std::cout << "Ｏ";
          break;
        case Batsu:
          std::cout << "Ｘ";
          break;
      }
    }

    /* must stack rows */
    std::cout << "\n";
  }
  std::cout << "\n＝＝＝＝＝\n\n";
}

bool canPlayMove(Board& board) {
  Move move; 
  std::cout << "移動先の行を入力してください: ";
  std::cin >> move.i;

  std::cout << "移動先の列を入力してください: ";
  std::cin >> move.j;

  move.i -= 1;
  move.j -= 1;

  if (board.bitBoard[move.i][move.j] != Empty) {
    return false;
  } else {

    switch (board.turn) {
      case Sente:
        board.bitBoard[move.i][move.j] = Maru;
        break;
      case Gote:
        board.bitBoard[move.i][move.j] = Batsu;
        break;
    }

    return true;
  }
}

bool isMate(Board board) {
  /* horizontal search */
  for (int i = 0; i < 3; i++) {
    if (board.bitBoard[i][0] == board.bitBoard[i][1] && board.bitBoard[i][1] == board.bitBoard[i][2] && board.bitBoard[i][0] != Empty) {
      return true;
    }
  }

  /* vertical search */
  for (int i = 0; i < 3; i++) {
    if (board.bitBoard[0][i] == board.bitBoard[1][i] && board.bitBoard[1][i] == board.bitBoard[2][i] && board.bitBoard[0][i] != Empty) {
      return true;
    }
  }

  /* diagonal search */
  if (board.bitBoard[0][0] == board.bitBoard[1][1] && board.bitBoard[1][1] == board.bitBoard[2][2] && board.bitBoard[0][0] != Empty) {
    return true;
  }
  if (board.bitBoard[0][2] == board.bitBoard[1][1] && board.bitBoard[1][1] == board.bitBoard[2][0] && board.bitBoard[0][2] != Empty) {
    return true;
  }

  return false;
}


int main() {
  int moveCount = 0;
  Board gameBoard;

  while(true) {
    clear();
    printBoard(gameBoard);

    while (!canPlayMove(gameBoard)) {
      std::cout << "別の手を選択してください\n";
    }

    if (isMate(gameBoard)) {
      std::cout << "まで" << moveCount << "手で";
      switch (gameBoard.turn) {
        case Sente:
          std::cout << "先手の勝ち\n";
          break;
        case Gote:
          std::cout << "後手の勝ち\n";
          break;
      }

      return 0;
    }

    gameBoard.switchTurn();
    moveCount += 1;
  }

  return 0;
}
