// 13519214
// Game Engine
#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "config.hpp"
#include "render.hpp"
#include "message.hpp"
#include "playerinput.hpp"
#include "entities/map.hpp"
#include "entities/player.hpp"
#include "entities/engimon.hpp"
#include "entities/position.hpp"
#include "entities/direction.hpp"
#include <vector>

class Engine {
    private:
        Map map;
        Message messageList;
        PlayerInput userInput;
        Player player;
        Render renderer;
        bool isEngineRunning;
        std::vector<Engimon*> engimonList;

        bool evaluteInput();
        // Evaluating input from PlayerInput class, if evaluated, return true
        void evaluteTick();
        // Evaluating next tick
        void moveEntity(Position pos, Direction dir);
        // Move entity at map to target direction without checking

    public:
        Engine();
        // Constructor
        ~Engine();
        // Destructor

        void startGame();
        // Start game
        void loadDatabase();
        // TODO : Needed (?)
};

#endif
