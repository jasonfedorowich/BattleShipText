#include "Sprite.h"
#include <iostream>
Sprite::Sprite(ShipType _shiptype)
{
	this->set = new std::map<Position, Cell*>();
	this->max_cells = _shiptype;

}

Sprite::~Sprite()
{
	for (auto cell = _set->begin(); cell!=_set->end(); cell++) {
		delete cell->second;
	}
	delete _set;
}

void Sprite::set(int row, int col)
{
	if (this->max_cells == _set->size())
		return;

	Cell* cell = new Cell(row, col);
	Position _position;
	_position.row = row;
	_position.col = col;
	(*this->_set)[_position] = cell;
}

void Sprite::draw(int row, int col)
{
	Position _position;
	_position.row = row;
	_position.col = col;
	if (_shiptype == ShipType::NONE) {
		switch ((*this->_set)[_position]->get_type()) {
		case SHOT_HIT:
			std::cout << "X";
			break;
		case BLANK:
			std::cout << "O";
			break;
		}
		
	}
	else {
		switch ((*this->_set)[_position]->get_type()) {
		case EXPLOSION:
			std::cout << "*";
			break;
		case BLANK:
			std::cout << "O";
			break;
		}
	}


}



Cell::Cell(int row, int col)
{
	this->_celltype = CellType::BLANK;
	this->row = row;
	this->col = col;

}

CellType Cell::get_type()
{
	return this->_celltype;
}
