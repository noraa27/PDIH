// Compilar con: gcc p2.c -o p2 -lncurses
#include <ncurses.h>
#include <unistd.h>
#define DELAY 900000
int main(int argc, char *argv[]) {
  int x = 2, y = 9; //posicion pelota
  int max_y = 25, max_x = 79;
  int next_x = 0;
  int directionx = 2;
  int next_y = 0;
  int directiony = 2;
  int rows=50, cols=80;
  bool seguir = true;
  int p1=0, p2=0; //Puntuaciones de los jugadores, inicialmente valen 0
  int jugador=1;
  int xc1 = 0, yc1 = 6; //POSICION JUGADOR IZQUIERDA
  int xc2 = 78, yc2 = 6; //POSICION JUGADOR DERECHA
  int ch = 0;
  initscr();
  noecho();
  cbreak();
  nodelay(stdscr, TRUE);
  start_color();
  init_pair(1, COLOR_YELLOW, COLOR_GREEN);
  init_pair(2, COLOR_WHITE,COLOR_BLACK);
  init_pair(3,COLOR_WHITE,COLOR_BLUE);
  while(1){
    mvprintw(5, 31, " ---------- ");
    mvprintw(6, 31, "|Juego Pong|");
    mvprintw(7, 31, " ---------- ");
    mvprintw(8, 32, "Controles");
    mvprintw(10, 24, "s --> Desplazar hacia abajo");
    mvprintw(11, 24, "w --> Desplazar hacia arriba");
    mvprintw(12, 10, "En la parte inferior aparece el jugador que tiene el control");
    mvprintw(14, 24, "Pulsar Enter para comenzar...");
    refresh();
    ch = getch();
    if ( ch == '\n'){
      seguir = false;
      while(seguir==false){
        usleep(DELAY);
        curs_set(FALSE);
        WINDOW *window = newwin(rows,cols,0,0);
        wbkgd(window, COLOR_PAIR(2));
        mvwprintw(window,y, x, "o");
        mvwprintw(window, yc1, xc1, "XX");
        mvwprintw(window, yc1+1, xc1, "XX");
        mvwprintw(window, yc1+2, xc1, "XX");
        mvwprintw(window, yc1+3, xc1, "XX");
        mvwprintw(window, yc2, xc2, "XX");
        mvwprintw(window, yc2+1, xc2, "XX");
        mvwprintw(window, yc2+2, xc2, "XX");
        mvwprintw(window, yc2+3, xc2, "XX");
        mvwprintw(window, 12, 0,
        "--------------------------------------------------------------------------------");
        if(jugador==1){
        mvwprintw(window, 14, 0, "Jugador actual: JUGADOR 1");
        }
        if(jugador==2){
        mvwprintw(window, 14, 0, "Jugador actual: JUGADOR 2");
        }
        mvwprintw(window, 16, 0, " ------------ ");
        mvwprintw(window, 17, 0, "|Puntuaciones|");
        mvwprintw(window, 18, 0, " ------------ ");
        mvwprintw(window, 19, 0, "JUGADOR 1: %i", p1);
        mvwprintw(window, 20, 0, "JUGADOR 2: %i", p2);
        mvwprintw(window, 16, 50, " --------- ");
        mvwprintw(window, 17, 50, "|Controles|");
        mvwprintw(window, 18, 50, " --------- ");
        mvwprintw(window, 19, 50, "s --> Desplazar hacia abajo");
        mvwprintw(window, 20, 50, "w --> Desplazar hacia arriba");
        wrefresh(window);
        //Comprobamos en qué lado del campo está la pelota, para poder asignar un
        jugador
        if(x > 38){
        jugador = 2;
        }
        else{
        jugador = 1;
        }
        next_x = x + directionx;
        next_y = y + directiony;
        if (next_x >= max_x || next_x < 0) {
          directionx*= -1;
        } else {
          x+= directionx;
        }
        if (next_y >= 12 || next_y < 0) {
          directiony*= -1;
        }else {
          y+= directiony;
        }
        //Realizamos los movimientos pertinentes
        ch = getch();
        if(jugador == 1){
          if (ch == 'w'){
            yc1 -= 2;
          }
          else if (ch == 's'){
            yc1 += 2;
          }
        }
        if(jugador == 2){
          if (ch == 'w'){
            yc2 -= 2;
          }
          else if (ch == 's'){
            yc2 += 2;
          }
        }
        //Puntuaciones
        if (next_x > xc2){
          next_x = xc2 - 1; //volvemos a la posición una unidad menor del máximo
          x = xc2 - 1; // del valor d x para el jugador 2
          p1++;
        }
        else if (next_x < xc1){
          next_x = xc1 + 1; //volvemos a la posición una unidad mayor del mínimo
          x = xc1 + 1; // del valor d x para el jugador 1
          p2++;
        }
      }
    }
  }
  endwin();
}
