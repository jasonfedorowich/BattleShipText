// BattleShip.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "BattleShip.h"


#define NUMBER_OF_DESTROYERS 4
#define NUMBER_OF_SUBMARINE 4
#define NUMBER_OF_CARRIERS 2
#define NUMBER_OF_BATTLESHIP 1
#define SIZE_OF_GRID 16

static bool game_is_running = true;
static bool game_is_updated = false;
static bool in_game = true;
static bool computer_updates = false;


static Grid* player_grid;
static Grid* computer_grid;



void destroy_all() {

    delete player_grid;
    delete computer_grid;
}

void init(int rows, int cols) {
    player_grid = new Grid(rows, cols);
    computer_grid = new Grid(rows, cols);
    init_grid(player_grid);
    init_grid(computer_grid);
}

void init_grid(Grid* grid) {

    create_ships(grid, NUMBER_OF_DESTROYERS, ShipType::DESTROYER);
    create_ships(grid, NUMBER_OF_SUBMARINE, ShipType::SUBMARINE);
    create_ships(grid, NUMBER_OF_CARRIERS, ShipType::CARRIER);
    create_ships(grid, NUMBER_OF_BATTLESHIP, ShipType::BATTLESHIP);
    fill(grid);
}

void fill(Grid* grid) {
    for (int i = 0; i < grid->get_max_rows(); i++) {
        for (int j = 0; j < grid->get_max_cols(); j++) {
            Sprite* sprite = new Sprite(ShipType::NONE);
            if (!grid->is_occupied(i, j)) {
                grid->set(sprite, i, j);
            }
        }
    }

}

bool fill_row(Grid* grid, int start_row, int end_row, int start_col, ShipType _shiptype) {
    Sprite* sprite = new Sprite(_shiptype);
    int i = start_row;
    while (i < end_row) {
        if (!grid->set(sprite, i++, start_col)) {
            delete sprite;
            sprite = NULL;
            return false;
        }
    }
    return true;
}

bool fill_col(Grid* grid, int start_col, int end_col, int start_row, ShipType _shiptype) {
    Sprite* sprite = new Sprite(_shiptype);
    int i = start_row;
    while (i < end_col) {
        if (!grid->set(sprite, start_row, i++)) {
            delete sprite;
            sprite = NULL;
            return false;
        }
    }
    return true;
}

void fill_cells(Grid* grid, ShipType _shiptype) {
    int start_row;
    int start_col;
    int end_row;
    int end_col;
    while (true) {
        start_row = rand() % grid->get_max_rows();
        start_col = rand() % grid->get_max_cols();
        if (!grid->is_occupied(start_row, start_col) && !grid->is_occupied((start_row +_shiptype)/2, start_col) && !grid->is_occupied(start_row + _shiptype, start_col)) {
            if (fill_row(grid, start_row, start_row + _shiptype, start_col, _shiptype)) {
                return;
              }
          }
        else if (!grid->is_occupied(start_row, start_col) && !grid->is_occupied(start_row, (start_col +_shiptype)/2) && !grid->is_occupied(start_row, start_col + _shiptype)) {
            if (fill_col(grid, start_col, start_col + _shiptype, start_row, _shiptype)) {
                return;
             }
        }
     
    }
   
}

void create_ships(Grid* grid, int number, ShipType _shiptype) {
    
    for (int i = 0; i < number; i++) {
        fill_cells(grid, _shiptype);
    }

   

}

void update_computer() {
    while (true) {
        int row = rand() % player_grid->get_max_rows();
        int col = rand() % player_grid->get_max_cols();
        if (!player_grid->toggle(row, col))
            break;
    }
   
}

void handle_user_inputer() {
    std::string line;
    std::getline(std::cin, line);
    if (line == "q") {
        game_is_running = false;
        in_game = false;
        game_is_updated = false;
    }
    else if (line == "r"){
        in_game = false;
            game_is_updated = false;
    }


}

void get_updates() {
    if (computer_updates) {
        update_computer();
    }
    else {
        std::cout << "Please enter coordinates of attack enter r to reset game or q to quit" << std::endl;
        handle_user_input();
    }

}

void update_game() {

}

void restart() {

}

int main()
{
    init(SIZE_OF_GRID, SIZE_OF_GRID);


    while (game_is_running) {
        while (in_game) {
            get_updates();
            if (game_is_updated) {
                update_game();
            }
        }
        restart();
       
    }
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
