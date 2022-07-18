#pragma once
#include <iostream>

#include "stateEngine.h"
#include "stateEngineOn.h"
#include "stateFighter.h"

class StoppedEngine : public StateEngine
{
public:
    StoppedEngine(FighterJet& fighter);
    void on() override;
    void off() override;
    void speedUp() override;
};