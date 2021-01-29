#include "Number.h"
using namespace bangtal;

#include "config.h"

#include <string>
using namespace std;

NumberPtr Number::create(ScenePtr scene, int x, int y, bool shown)
{
	auto number = NumberPtr(new Number(scene, x, y, shown));
	Object::add(number);

	return number;
}

Number::Number(ScenePtr scene, int x, int y, bool shown)
	: Object("", scene, x, y, shown)
{
}

void Number::setNumber(int n)
{
	if (n >= 0 && n < 10) {
#ifdef WIN32
		string image = IMAGE_PATH + to_string(n) + ".png";
#else
		string image = to_string(n) + ".png";
#endif
		setImage(image);
		show();
	}
	else {
		setImage("");
		hide();
	}
}
