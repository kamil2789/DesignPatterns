#include <memory>
#include <iostream>

#include "stateEngine.h"
#include "stateEngineOn.h"
#include "stateFighter.h"
#include "stateEngineOff.h"

StoppedEngine::StoppedEngine(FighterJet& fighter):
     StateEngine(fighter)
    {}

void StoppedEngine::on()
{
    std::cout<<"START THE ENGINE\n";
    fighter.changeState(std::make_unique<RunningEngine>(fighter));
}

void StoppedEngine::off()
{
    std::cout<<"ENGINE ALREADY STOPPED\n";
}

void StoppedEngine::speedUp()
{
    std::cout<<"CANNOT SPEED UP STOPPED ENGINE\n";
}

RunningEngine::RunningEngine(FighterJet& fighter):
    StateEngine(fighter)
{}

void RunningEngine::on()
{
    std::cout<<"ENGINE ALREADY STARTED\n";
}

void RunningEngine::off()
{
    std::cout<<"START LOSING SPEED\n";
    fighter.changeState(std::make_unique<StoppedEngine>(fighter));
}

void RunningEngine::speedUp()
{
    std::cout<<"INCREASE SPEED\n";
}

FighterJet::FighterJet():
    engine(std::make_unique<StoppedEngine>(*this))
{}

void FighterJet::on()
{
    engine->on();
}
void FighterJet::off()
{
    engine->off();
}

void FighterJet::speedUp()
{
    engine->speedUp();
}

void FighterJet::log()
{
    std::cout<<"STATUS\n";
}

void FighterJet::changeState(std::unique_ptr<StateEngine> state)
{   
    engine = std::move(state);
}

int main()
{
    FighterJet tomcat{};
    tomcat.speedUp();
    tomcat.on();
    tomcat.on();
    tomcat.speedUp();
    tomcat.off();
    tomcat.speedUp();

    return 0;
}
