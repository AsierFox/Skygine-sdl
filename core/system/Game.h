#ifndef _GAME_H_
#define _GAME_H_

#include "System.h"

#include "data/GameData.h"

class Game : public System {
public:

	Game(GameData data);
	virtual ~Game();
};

#endif // !_GAME_H_
