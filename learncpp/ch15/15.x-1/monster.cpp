#include "monster.h"
#include "random.h"
#include <string_view> // already incl in monster.h but prob clearer this way
#include <iostream>

std::string_view Monster::getTypeString() const	{
	switch (m_type)	{
		case dragon: 	return "dragon"; 	break;
		case goblin: 	return "goblin"; 	break;
		case ogre: 		return "ogre"; 		break;
		case orc: 		return "orc"; 		break;
		case skeleton: 	return "skeleton"; 	break;
		case troll:		return "troll"; 	break;
		case vampire: 	return "vampire"; 	break;
		case zombie: 	return "zombie"; 	break;
		default: return "unknown type";
	}
}

void Monster::print() const	{
	std::cout << m_name << " the " << getTypeString() << " has " << m_hp
				<< " hit points and says " << m_roar << '\n';
}


namespace MonsterGenerator	{
	Monster generate()	{
		return Monster {
		  	(static_cast<Monster::Type> (Random::get(0, 
		  		Monster::maxMonsterTypes -1))),
			getName(Random::get(0, 5)),
			getRoar(Random::get(0, 5)),
			Random::get(1, 100)};
	}


	std::string_view getName(int nameCode)	{
		switch (nameCode)	{
			case 0:		return "Bob"; 	break;
			case 1:		return "Rob"; 	break;
			case 2:		return "Jim"; 	break;
			case 3:		return "Slim"; 	break;
			case 4:		return "Pim"; 	break;
			case 5:		
			default:		return "Gob"; 	break;
		}
	}

	std::string_view getRoar(int roarCode)	{
		switch (roarCode)	{
			case 0:		return "*roar*"; 	break;
			case 1:		return "*rattle*"; 	break;
			case 2:		return "*meow*"; 	break;
			case 3:		return "*grrr*"; 	break;
			case 4:		return "Pim"; 	break;
			case 5:		
			default:		return "hey man hows it goin"; 	break;
		}
	}
}
