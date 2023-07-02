#include "Map.h"


 std::array<Line, 20> Map::lines;

 Map::Map()
 {
	 setupLines();
	 setupLinesPostion();
 }

 void Map::checkFullLines(int index)
 {
	bool full =	 lines[index].checkFullLine();

	clearLine(full, index);
 }

 void Map::clearLine(bool full, int index)
 {
	 if (full)
	 {
		 for (int i = index; i >= 0; i--)
		 {
			 if (i == 0)
			 {
				 continue;
			 }
			 else
			 {

			 lines[i] = lines[i - 1];
			 }
		 }
		 

	 }
		 

 }

 void Map::setupLines()
 {
	
	 for (int i = 0; i < lines.size(); i++)
		 lines[i] = line;

 }

 void Map::setupLinesPostion()
 {
	     int nextY = 0;
	 for (int i = 0; i < lines.size(); i++)
	 {
		 lines[i].setLineLocation(nextY);
		 nextY += 25;
	 }

 }

 void Map::setStatesTest()
 {
	 for (int i = 0; i < lines.size(); i++)
		 lines[i].setLineState(i);
 }

 void Map::draw(sf::RenderWindow& window)
 {

	 for (int i = 0; i < lines.size(); i++)
		 lines[i].draw(&window);
 }

 std::array<Line, 20>& Map::getLines()
 {
	 return lines;
 }