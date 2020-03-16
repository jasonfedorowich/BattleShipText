#include "Grid.h"
#include <iostream>
Grid::Grid(int rows, int cols)
{
	this->_grid = new std::vector<std::vector<Sprite*>*>();
	for (int i = 0; i < rows; i++) {
		std::vector<Sprite*>* column = new std::vector<Sprite*>();
		int j = 0;
		while (j++ < cols) {
			column->push_back(nullptr);
		}
		this->_grid->push_back(column);
	}
	this->rows = rows;
	this->cols = cols;

}

Grid::~Grid()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			Sprite* sprite = get(i, j);
			delete sprite;
		}
	}
	delete _grid;
}

void Grid::clear()
{
}

void Grid::draw()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			Sprite* sprite = get(i, j);
			sprite->draw(i, j);
			
		}
		std::cout << std::endl;
	}
}

Sprite* Grid::get(int row, int col)
{
	if (row >= this->rows || col >= this->cols)
		return nullptr;
	return (*(*this->_grid)[row])[col];
}

bool Grid::set(Sprite* sprite, int row, int col)
{
	if (is_occupied(row, col))
		return false;
	std::vector<Sprite*>* column = (*this->_grid)[row];
	column->insert(column->begin() + col, sprite);
	sprite->set(row, col);

}

bool Grid::is_occupied(int row, int col)
{
	if (row >= this->rows || col >= this->cols)
		return true;
	return (get(row, col) != nullptr || get(row, col) != NULL);
}

bool Grid::toggle(int row, int col)
{
	get()
}

int Grid::get_max_rows()
{
	return rows;
}

int Grid::get_max_cols()
{
	return cols;
}
