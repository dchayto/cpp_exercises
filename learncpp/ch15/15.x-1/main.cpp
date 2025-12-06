/* create a random monster generator (think RPG):
	a) First, create an scoped enumeration of monster types named MonsterType.
	   Include types: Dragon, Goblin, Ogre, Orc, Skeleton, Troll, Vampire, and 
	   Zombie. Add an additional maxMonsterTypes enumerator so we can count 
	   how many enumerators there are.

	b) Now, let’s create our Monster class. Our Monster will have 4 attributes
	   (member variables): a type (MonsterType), a name (std::string), a roar 
	   (std::string) and the number of hit points (int).

	c) enum class MonsterType is specific to Monster, so make MonsterType a 
	   nested unscoped enum inside Monster and rename it to Type.

	d) Create a constructor to initialize all of the member variables.

	e) Now we want to be able to print our monster so we can validate it’s 
	   correct. Write two functions: One called getTypeString() that returns 
	   the monster’s type as a string, and one called print() that matches the
	   output in the sample program below.

	f) Create a MonsterGenerator namespace. Create function within named
	   generate(). This should return a Monster. For now, make it return
	   Monster{ Monster::skeleton, "Bones", "*rattle*", 4};

	g) Add two more functions to the MonsterGenerator namespace. getName(int)
	   will take a number between 0 and 5 (inclusive) and return a name of your
	   choice. getRoar(int) will also take a number between 0 and 5 (inclusive)
	   and return a roar of your choice. Also update your generate() function
	   to call getName(0) and getRoar(0).

	h) Now we’ll randomize our generated monster. Grab the “Random.h” code from
	   8.15 -- Global random numbers (Random.h) and save it as Random.h. Then
	   use Random::get() to generate a random monster type, random name, random
	   roar, and random hit points (between 1 and 100).
*/

#include "monster.h"

int main()
{
//	Monster m { Monster{Monster::dragon, "sldkjf", "skdfj", 30} }; 

	Monster m{ MonsterGenerator::generate() };
	m.print();

	return 0;
}
