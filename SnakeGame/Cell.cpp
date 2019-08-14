#include "Cell.h"

Cell::Cell(int i_, int j_, int w_) : i(i_), j(j_), w(w_), _type(CellType::CellEmpty)
{
}
Cell::~Cell()
{
};
const CellType& Cell::getType() const
{
	return _type;
}
void Cell::setType(CellType type)
{
	_type = type;
}
;
int Cell::col() const
{
	return j;
}
int Cell::row() const
{
	return i;
}
;

void Cell::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	int posX = j * w;
	int posY = i * w;

	sf::RectangleShape rect(sf::Vector2f((float)w, (float)w));

	rect.setPosition(sf::Vector2f((float)posX, (float)posY));
	rect.setOutlineThickness(-1);
	rect.setOutlineColor(sf::Color(204, 204, 204));

	sf::Color color;
	switch (_type)
	{
	case CellFood:
		color = sf::Color::Magenta;
		break;
	case CellSnakePart:
		color = sf::Color::Green;
		break;
	default:
		color = sf::Color::Color();
		break;
	}

	rect.setFillColor(color);
	target.draw(rect, states);
};
