#include "Collison.h"


bool Collison::checkCollison(sf::RectangleShape* shape1,Block* block,Map* map)
{

    for (int i = 0; i < block->getShapes().size(); i++)
    {
    bool collisionX = shape1->getPosition().x + shape1->getSize().x >= block->getShapes()[i].getPosition().x &&
        block->getShapes()[i].getPosition().x + block->getShapes()[i].getSize().x >= shape1->getPosition().x;
    bool collisionY = shape1->getPosition().y + shape1->getSize().y >= block->getShapes()[i].getPosition().y &&
        block->getShapes()[i].getPosition().y + block->getShapes()[i].getSize().y >= shape1->getPosition().y;


    bool activeState = map->getLines()[block->getShapesPostions()[i].y - 1].getshapesStates()[block->getShapesPostions()[i].x - 1];


    if (collisionX && collisionY && !activeState)
    {
        return true;
    }
    else if (collisionX && collisionY && activeState)
    {
        return false;
      }
 
    }


    return false;


}

bool Collison::checkCollison(Map* map, Block* block)
{

    for (int i = 0; i < 4; i++)
    {
        bool collisionX = map->getLines()[block->getShapesPostions()[i].y - 1].getShapes()[block->getShapesPostions()[i].x - 1].getPosition().x + map->getLines()[block->getShapesPostions()[i].y - 1].getShapes()[block->getShapesPostions()[i].x - 1].getSize().x >= block->getShapes()[i].getPosition().x
            && block->getShapes()[i].getPosition().x + block->getShapes()[i].getSize().x >= map->getLines()[block->getShapesPostions()[1].y - 1].getShapes()[block->getShapesPostions()[1].x - 1].getPosition().x;

        bool collisionY = map->getLines()[block->getShapesPostions()[i].y - 1].getShapes()[block->getShapesPostions()[i].x - 1].getPosition().y + map->getLines()[block->getShapesPostions()[i].y - 1].getShapes()[block->getShapesPostions()[i].x - 1].getSize().y >= block->getShapes()[i].getPosition().y
            && block->getShapes()[i].getPosition().y + block->getShapes()[i].getSize().y >= map->getLines()[block->getShapesPostions()[1].y - 1].getShapes()[block->getShapesPostions()[1].x - 1].getPosition().y;
       

        bool activeState = map->getLines()[block->getShapesPostions()[i].y - 1].getshapesStates()[block->getShapesPostions()[i].x - 1];
        bool activeState1 = map->getLines()[block->getShapesPostions()[1].y - 1].getshapesStates()[block->getShapesPostions()[1].x - 1];
        bool activeState4 = map->getLines()[block->getShapesPostions()[3].y - 1].getshapesStates()[block->getShapesPostions()[3].x - 1];


        
        if (collisionX && collisionY && activeState)
        {
            return true;
        }
        else if (collisionX && collisionY && activeState1)
        {
            return true;
        }
        else if (collisionX && collisionY && activeState4)
        {
            return true;
        }
       
      
      
    }
    return false;
}

void Collison::doCollison(sf::RectangleShape& shape1, Block& block,Map& map)
{

    if (block.getSpawnState())
    {
        bool collison_check = checkCollison(&shape1, &block, &map);


        if (collison_check)
        {



            for (int i = 0; i < block.getShapes().size(); i++)
            {
                map.getLines()[block.getShapesPostions()[i].y - 1].setTexture(block.getColorNumber());

                if (block.getShapesPostions()[i].y - 1 >= 20)
                {
                    block.getShapesPostions()[i].y -= 1;
                }
                map.getLines()[block.getShapesPostions()[i].y - 1].setLineState(block.getShapesPostions()[i].x);

            }


            block.deSpawnState();
            block.spawn();


            for (int i = 0; i < 20; i++)
                map.checkFullLines(i);
 

        }
      
    }

  


}


void Collison::doCollison(Block& block, Map& map)
{
    
    if (block.getSpawnState())
    {
        checkGameOver(&map,&block);

        bool collison_check = checkCollison(&map, &block);
        if (collison_check)
        {



            for (int i = 0; i < block.getShapes().size(); i++)
            {

                map.getLines()[block.getShapesPostions()[i].y - 1].setTexture(block.getColorNumber());
                map.getLines()[block.getShapesPostions()[i].y - 2].setTexture(block.getColorNumber());
                map.getLines()[block.getShapesPostions()[i].y - 2].setLineState(block.getShapesPostions()[i].x);

            }

            block.deSpawnState();
            block.spawn();
   

            for (int i = 0; i < 20; i++)
                map.checkFullLines(i);

        }
     
    }

   


}






void Collison::checkGameOver(Map* map, Block* block)
{
    
    for (int i = 0; i < 4; i++)
    {
        bool collisionX = map->getLines()[0].getShapes()[block->getShapesPostions()[i].x - 1].getPosition().x + map->getLines()[0].getShapes()[block->getShapesPostions()[i].x - 1].getSize().x >= block->getShapes()[i].getPosition().x
            && block->getShapes()[i].getPosition().x + block->getShapes()[i].getSize().x >= map->getLines()[0].getShapes()[block->getShapesPostions()[1].x - 1].getPosition().x;

        bool collisionY = map->getLines()[0].getShapes()[block->getShapesPostions()[i].x - 1].getPosition().y + map->getLines()[0].getShapes()[block->getShapesPostions()[i].x - 1].getSize().y >= block->getShapes()[i].getPosition().y
            && block->getShapes()[i].getPosition().y + block->getShapes()[i].getSize().y >= map->getLines()[0].getShapes()[block->getShapesPostions()[1].x - 1].getPosition().y;
       

        bool activeState = map->getLines()[block->getShapesPostions()[i].y - 1].getshapesStates()[block->getShapesPostions()[i].x - 1];


        
        if (collisionX && collisionY && activeState)
        {
            std::cout << "GAME OVER " << std::endl;
            exit(0);
        }
     

       
      
      
    }
}

