#pragma once
#include <bangtal>

class Number;
typedef std::shared_ptr<Number> NumberPtr;

class Number : public bangtal::Object
{
public:
	static NumberPtr create(bangtal::ScenePtr scene, int x, int y, bool shown = true);

protected:
	Number(bangtal::ScenePtr scene, int x, int y, bool shown = true);

public:
	void setNumber(int n);
};

