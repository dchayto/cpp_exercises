#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <string_view>

class Monster	{
public:
	enum Type	{
		dragon,
		goblin,
		ogre,
		orc,
		skeleton,
		troll,
		vampire,
		zombie,	
		maxMonsterTypes,
	};

	Monster()
		: m_type { static_cast<Type> (0)}
		, m_name { }
		, m_roar { }
		, m_hp { }
	{}

	Monster(Type type, std::string_view name, std::string_view roar, int hp)
		: m_type 	{ type }
		, m_name 	{ name }
		, m_roar 	{ roar }
		, m_hp		{ hp }
	{}

	std::string_view getTypeString() const;
	void print() const;

private:
	Type m_type;
	std::string m_name;	
	std::string m_roar;
	int m_hp;
};

namespace MonsterGenerator	{
	Monster generate();
	std::string_view getName(int nameCode);
	std::string_view getRoar(int roarCode);
}

#endif
