#pragma once
#include <string>

#ifndef _HERO_H_
#define _HERO_H_

enum HeroClass { NONE = -1, WARRIOR, MAGE, ROGUE };

class Hero
{
friend class HeroFactory;

private:
	std::string name = "";
	HeroClass hero_class = NONE;

	int strength = 0;
	int dexterity = 0;
	int perception = 0;
	int intelligence = 0;
	int charisma = 0;

public:

	Hero() {};
	Hero(std::string& name, HeroClass hero_class) : name(name), hero_class(hero_class) { setStats(); };

	void drawInfo();
	void setStats();

	void setName(char* out_name) { name = out_name; };
	void setClass(HeroClass h_class) { hero_class = h_class; };

	// Error 3: Hero::getClass() could be const
	/*const*/ HeroClass getClass() { return hero_class; }
};

#endif