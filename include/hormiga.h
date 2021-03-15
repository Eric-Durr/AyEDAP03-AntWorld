/*   
  Copyright (c) 2020 Eric Dürr Sierra, Todos los derechos reservados.

  Escuela Superior de Ingeniería y Tecnología.  
  Algoritmos y Estructuras de Datos Avanzados | ULL 2º curso de Ingeniería Informática
    
  Fecha de creación:            09/03/2021
  Fecha de última modificación: 09/03/2021
 
  Fichero que describe la clase que representa 
  el autómata de la hormiga.

  Realizado por: Eric Dürr Sierra (alu0101027005)
  e-mail:        eric.durr.20@ull.edu.es
 */
#include <iostream>
#include <vector>
#include <string>

#define ARR_U "↑"
#define ARR_UR "↗"
#define ARR_R "→"
#define ARR_RD "↘"
#define ARR_D "↓"
#define ARR_DL "↙"
#define ARR_L "←"
#define ARR_LU "↖"

enum direction
{
  UP,
  UR,
  RI,
  RD,
  DO,
  DL,
  LE,
  LU
};

enum direction_color
{
  WH,
  BL,
};

class LangtonAnt
{
private:
  int pos_i_, pos_j_;
  int dir_;

public:
  LangtonAnt(int pos_i = -1, int pos_j = -1, direction dir = LE);

  const std::vector<int> current_pos(void) const;
  void mod_pos(const int &new_i, const int &new_j);

  const int current_dir(void) const;
  void mod_dir(const int &new_dir);

  const int check_environment(const bool &slot_color);
  const direction_color switch_color(const bool &slot_color);

  std::string to_string(void) const;

private:
  void rotate_ant(int rule);
  void move_ant(void);
};