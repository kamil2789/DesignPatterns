trait StateEngine {
    fn on(&self) -> Option<Box<dyn StateEngine>>;
    fn off(&self) -> Option<Box<dyn StateEngine>>;
    fn speed_up(&self) -> u16;
}

struct StateEngineOff {

}

impl StateEngine for StateEngineOff {
    fn on(&self) -> Option<Box<dyn StateEngine>>{
        println!("ENGINE ON");
        Some(Box::new(StateEngineOn{}))
    }

    fn off(&self) -> Option<Box<dyn StateEngine>> {
        println!("ENGINE ALREADY STOPPED");
        None
    }

    fn speed_up(&self) -> u16 {
        println!("CANNOT SPEED UP STOPPED ENGINE");
        0
    }
}

struct StateEngineOn {

}

impl StateEngine for StateEngineOn {
    fn on(&self) -> Option<Box<dyn StateEngine>>{
        println!("ENGINE ALREADY STARTED");
        None
    }

    fn off(&self) -> Option<Box<dyn StateEngine>> {
        println!("ENGINE OFF");
        Some(Box::new(StateEngineOff{}))
    }

    fn speed_up(&self) -> u16 {
        println!("INCREASE SPEED BY 10");
        10
    }
}

pub struct FighterJet {
    state: Box<dyn StateEngine>,
    speed: u16
}

impl FighterJet {
    pub fn new() -> Self {
        FighterJet{state: Box::new(StateEngineOff{}), speed: 0}
    }

    fn on(&mut self) {
        if let Some(new_state) = self.state.on() {
            self.state = new_state;
        }
    }

    fn off(&mut self) {
        if let Some(new_state) = self.state.off() {
            self.state = new_state;
        }
    }

    fn speed_up(&mut self) {
        self.speed += self.state.speed_up();
    }
}


fn main() {
    let mut fighter_f16 = FighterJet::new();
    println!("{}", fighter_f16.speed);
    fighter_f16.off();
    fighter_f16.speed_up();
    fighter_f16.on();
    fighter_f16.speed_up();
    fighter_f16.on();
    fighter_f16.off();
    fighter_f16.off();
}
