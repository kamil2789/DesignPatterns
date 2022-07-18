#pragma once

class FighterJet;
class StateEngine
{
public:
    StateEngine(FighterJet& fighter):
        fighter(fighter)
    {}
    virtual ~StateEngine() = default;
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void speedUp() = 0;

    FighterJet& fighter;
};