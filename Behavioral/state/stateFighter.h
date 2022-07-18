#pragma once
#include <memory>
#include <iostream>

class FighterJet
{
public:
    FighterJet();
    void on();
    void off();
    void speedUp();
    void log();
    void changeState(std::unique_ptr<StateEngine> state);
private:
    std::unique_ptr<StateEngine> engine;
};