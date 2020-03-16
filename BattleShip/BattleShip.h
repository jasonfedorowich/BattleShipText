#pragma once
#include "Sprite.h"
#include "Grid.h"
void create_ships(Grid* grid, int number, ShipType _shiptype);
void fill_cells(Grid* grid, ShipType _shiptype);
void destroy_all();
void init(int rows, int cols);
void init_grid(Grid* grid);
void fill(Grid* grid);
void fill_cells(Grid* grid, ShipType _shiptype);
void create_ships(Grid* grid, int number, ShipType _shiptype);
void get_updates();
void update_game();
void restart();
void update_computer();
void handle_user_input();