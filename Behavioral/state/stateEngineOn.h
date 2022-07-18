#pragma once
#include <iostream>

#include "stateEngine.h"
#include "stateFighter.h"

class RunningEngine : public StateEngine
{
public:
    RunningEngine(FighterJet& fighter);
    void on() override;
    void off() override;
    void speedUp() override;
};