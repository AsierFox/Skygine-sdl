#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include "base\BaseObject.h"

/**
 * System class for the Engine different System parts.
 */
class System : public BaseObject {
public:
	enum Type {
		WINDOW,
		GAME,
		GRAPHICS,
		INPUT,
		TIMER
	};

	struct Data {
		Data();
	};

	System();
	virtual ~System();

	Type getType();

protected:
	Type type;

};

#endif // !_SYSTEM_H_
