/*   
  Copyright (c) 2020 Eric Dürr Sierra, Todos los derechos reservados.

  Escuela Superior de Ingeniería y Tecnología.  
  Algoritmos y Estructuras de Datos Avanzados | ULL 2º curso de Ingeniería Informática
    
  Fecha de creación:            20/02/2021
  Fecha de última modificación: 22/02/2021
 
  Fichero para la implementación de los métodos 
  de la clase entorno

  Realizado por: Eric Dürr Sierra (alu0101027005)
  e-mail:        eric.durr.20@ull.edu.es
 */

#include "../include/entorno_expansivo.h"

ExpLangtonEnvironment::ExpLangtonEnvironment(const int &n_rows, const int &n_cols,
                                             const int &ant_pos_i,
                                             const int &ant_pos_j,
                                             const direction &ant_dir)
    : cols_(n_cols), rows_(n_rows), steps_(0)
{
  init_grid(this->grid_, this->rows_, this->cols_);
  ant_ = LangtonAnt{ant_pos_i, ant_pos_j, ant_dir};
}

const bool ExpLangtonEnvironment::all_white(void) const
{
  for (int i = 0; i < this->rows_; i++)
  {
    for (int j = 0; j < this->cols_; j++)
    {
      if (this->grid_[i][j] == BL)
        return false;
    }
  }

  return true;
}

/* STRING OUTPUT METHOD */
const std::string ExpLangtonEnvironment::to_string(void) const
{
  std::string output = "";

  /* top border */
  output += "\n┌";
  for (int k = 0; k < (cols_ * 3); k++)
    output += "─";
  output += "┐\n";
  /* ---------- */

  /* center part */

  for (int i = 0; i < rows_; i++)
  {
    output += "│";
    for (int j = 0; j < cols_; j++)
    {
      if (this->ant_at() == std::vector<int>{i, j})
      {
        output += (" " + ant_.to_string() + " ");
      }
      else
      {
        grid_[i][j] == WH ? output += "   " : output += " x ";
      }
    }
    output += "│\n";
  }
  /* ------------ */

  /* bottom border */
  output += "└";
  for (int k = 0; k < (cols_ * 3); k++)
    output += "─";
  output += "┘\n";
  /* ------------- */

  return output;
}

void ExpLangtonEnvironment::step(const int &times)
{
  steps_ += times;
  direction_color current_slot;
  for (int i = 0; i < times; i++)
  {
    current_slot = grid_[ant_at()[0]][ant_at()[1]];

    grid_[ant_at()[0]][ant_at()[1]] = ant_.switch_color(current_slot);

    ant_.check_environment(current_slot);

    if (this->ant_hit_up())
      this->add_row_up(1);

    if (this->ant_hit_right())
      this->add_col_right(1);

    if (this->ant_hit_down())
      this->add_row_down(1);

    if (this->ant_hit_left())
      this->add_col_left(1);
  }
}

std::ostream &operator<<(std::ostream &os, const ExpLangtonEnvironment &this_object)
{
  os << this_object.to_string();
  return os;
}

/* --- PRIVATE METHODS --- */

void ExpLangtonEnvironment::add_col_right(const int &n)
{
  CustomVector<CustomVector<direction_color>> new_grid;
  init_grid(new_grid, this->rows_, this->cols_ + n);
  copy_state(new_grid, 0, n);
  // variable update
  this->grid_ = new_grid;
  this->cols_ += n;
}

void ExpLangtonEnvironment::add_col_left(const int &n)
{

  CustomVector<CustomVector<direction_color>> new_grid;
  init_grid(new_grid, this->rows_, this->cols_ + n);
  copy_state(new_grid, 0, n);
  // variable update
  this->grid_ = new_grid;
  this->cols_ += n;

  ant_.mod_pos(this->ant_at()[0], this->ant_at()[1] + n);
}

void ExpLangtonEnvironment::add_row_down(const int &n)
{
  CustomVector<CustomVector<direction_color>> new_grid;
  init_grid(new_grid, this->rows_ + n, this->cols_);
  copy_state(new_grid, n, 0);
  // variable update
  this->grid_ = new_grid;
  this->rows_ += n;
  rows_ += n;
  grid_ = new_grid;
}

void ExpLangtonEnvironment::add_row_up(const int &n)
{
  CustomVector<CustomVector<direction_color>> new_grid;
  init_grid(new_grid, this->rows_ + n, this->cols_);
  copy_state(new_grid, n, 0);
  // variable update
  this->grid_ = new_grid;
  this->rows_ += n;
  rows_ += n;
  grid_ = new_grid;

  ant_.mod_pos(this->ant_at()[0] + n, this->ant_at()[1]);
}

const bool ExpLangtonEnvironment::ant_hit_up(void) const
{
  return this->ant_at()[0] < 0;
}
const bool ExpLangtonEnvironment::ant_hit_right(void) const
{
  return this->ant_at()[1] >= cols_;
}
const bool ExpLangtonEnvironment::ant_hit_down(void) const
{
  return this->ant_at()[0] >= rows_;
}
const bool ExpLangtonEnvironment::ant_hit_left(void) const
{
  return this->ant_at()[1] < 0;
}

void ExpLangtonEnvironment::init_grid(CustomVector<CustomVector<direction_color>> &grid, int rows, int cols)
{

  grid.resize(0, rows);
  for (int i = 0; i < this->rows_; i++)
  {
    grid[i].resize(0, cols);
    for (int j = 0; j < this->cols_; j++)
    {
      grid[i][j] = WH;
    }
  }
}

CustomVector<CustomVector<direction_color>> ExpLangtonEnvironment::copy_state(
    CustomVector<CustomVector<direction_color>> &new_grid,
    const int &offset_n, const int &offset_m)
{
  for (int i = this->grid_.low_boundry(); i < this->grid_.top_boundry(); i++)
  {
    for (int j = this->grid_[i].low_boundry(); j < this->grid_[i].top_boundry(); j++)
    {
      new_grid[i + offset_n][j + offset_n] = this->grid_[i][j];
    }
  }
}
