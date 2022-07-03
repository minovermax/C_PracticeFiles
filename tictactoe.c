#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h> // boolean이 기본 포함이 안되어 있다니 ...

char board[3][3];
const char PLAYER = 'X';
const char OPPONENT = 'O';

// 2022.06.16
//   이런 식으로 모든 함수들을 한번씩 define 해주자. 이유는 밑에.
void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main(){
  char winner = ' ';
  
  resetBoard();

  while(winner == ' ' && checkFreeSpaces() != 0){
    printBoard();

    playerMove();
    
    printBoard();

    if(winner != ' ' || checkFreeSpaces() == 0){
      break;
    }
    
    computerMove();

    winner = checkWinner();

    if(winner != ' ' || checkFreeSpaces() == 0){
      break;
    }
  }

  printf("\n============\n\n");
  printBoard();
  printWinner(winner);

  return 0;

}

void resetBoard(){
  for(int i = 0; i < 3; ++i) {
    for(int j = 0; j < 3; ++j) {
      board[i][j] = ' ';
    }
  }
}

void printBoard(){
  printf(" %c | %c | %c", board[0][0], board[0][1], board[0][2]);
  printf("\n---|---|---\n");
  printf(" %c | %c | %c", board[1][0], board[1][1], board[1][2]); // 2022.06.16 첫째 variable [1][1] 로 해서 이상했었음
  printf("\n---|---|---\n");
  printf(" %c | %c | %c", board[2][0], board[2][1], board[2][2]); // 2022.06.16 첫째 variable [2][1] 로 해서 이상했었음
  printf("\n");
}

int checkFreeSpaces(){
  int freeSpaces = 9;

  for(int i = 0; i < 3; ++i) {
    for(int j = 0; j < 3; ++j) {
      if(board[i][j] != ' ') {
        --freeSpaces;
      }
    }
  }

  return freeSpaces;
}
void playerMove(){
  int x;
  int y;

  do {
    printf("X Enter row #(1-3): ");
    scanf("%d", &x);
    --x;

    printf("X Enter column #(1-3): ");
    scanf("%d", &y);
    --y;

    if(board[x][y] != ' ') {
      printf("X Invalid move!\n");
    } else {
      board[x][y] = PLAYER;
      break;
    }
  } while(board[x][y] != ' ');
}

// printWinner() 밑에 있다가 여기로 옮김. 이유는 밑에 내려보면 있다
// 2022.06.16   
//   더 알아보니 코드 맨 위 처럼 모든 함수들을 한번 define 해주면
//   함수의 순서를 상관해야하는 번거로움을 없앨 수 있다.
void printWinner(char winner){
  if(winner == PLAYER){
    printf("\nX Wins!");
  } else if(winner == OPPONENT){
    printf("\nO Wins!");
  } else {
    printf("\nIt's a Tie!");
  }
}

void computerMove(){
  int x;
  int y;

  do {
    printf("O Enter row #(1-3): ");
    scanf("%d", &x);
    --x;

    printf("O Enter column #(1-3): ");
    scanf("%d", &y);
    --y;

    if(board[x][y] != ' ') {
      printf("O Invalid move!\n");
    } else {
      board[x][y] = OPPONENT;
      break;
    }
  } while(board[x][y] != ' ');
}

char checkWinner(){
  
  // check rows
  for(int i = 0; i < 3; ++i){
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
      return board[i][0];
    }
  }
  // check columns
  for(int i = 0; i < 3; ++i){
    if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
      return board[0][i];
    }
  }
  // check diagonals
  for(int i = 0; i < 3; ++i){
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
      return board[0][0];
    }
  }
  for(int i = 0; i < 3; ++i){
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0]){
      return board[0][2];
    }
  }

  return ' ';
  
}
// 2022.06.15
//   원래는 printWinner()을 이 자리에 놨다.
//   하지만 여기에 printWinner() 넣으면 "conflicting types" 에러가 떴다.
//   이유는 위 computerMove()에서 printWinner() 사용하기 때문.
//   C는 위에서부터 읽어서 function을 프로그램에서 정의하기 전에 사용하면
//   뒤에 있더라도 return type을 자동으로 int로 인식하기에 compile 불가하다.
//   그렇기에 function을 사용할것이라면 먼저 정의를 하고 사용하는 습관을 들이자.
//   printWinner()를 computerMove() 전에 써놓으니 에러가 사라졌다.
