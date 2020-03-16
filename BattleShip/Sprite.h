#pragma once
#include <vector>
#include <unordered_set>
#include <map>
class Sprite
{

private:

	ShipType _shiptype;
	std::map<Position, Cell*>* _set;
	int max_cells;

protected:
     

public:
	Sprite(ShipType _shiptype);
	~Sprite();

	void set(int, int);
	void draw(int, int);

};

enum ShipType {

	NONE = 1,
	DESTROYER = 2,
	SUBMARINE = 3,
	CARRIER = 4,
	BATTLESHIP = 5
};


enum CellType {

	BLANK,
	SHOT_HIT,
	EXPLOSION

};

struct Position {
	int row;
	int col;
};

class Cell {
private:
	CellType _celltype;
	int row, col;

public:
	Cell(int, int);
	CellType get_type();

};

