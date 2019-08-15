#pragma once
#include <SFML/Graphics.hpp>

enum CellType { CellEmpty = 0, CellFood, CellSnakePart, CellHead };

class Cell: public sf::Drawable
{
public:
	Cell(int i_, int j_, int w_);
	~Cell();

	const CellType& getType() const;
	void setType(CellType type);

	int col() const;
	int row() const;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	CellType _type;
	int i, j, w;
};

