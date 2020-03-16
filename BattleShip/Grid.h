#pragma once
#include <vector>
#include "Sprite.h"
class Grid
{
private:
	std::vector<std::vector<Sprite*>*>* _grid;
	int rows, cols;
public:
	Grid(int, int);
	~Grid();

	void clear();

	void draw();
	Sprite* get(int, int);
	bool set(Sprite*, int, int);

	bool is_occupied(int, int);
	bool toggle(int, int);

	int get_max_rows();
	int get_max_cols();
};

