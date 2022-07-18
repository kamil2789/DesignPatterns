class StateEngine:
    def on(self):
        pass

    def off(self):
        pass

    def speed_up(self):
        pass


class FighterJet:
    def __init__(self):
        self.speed = 0
        self.state = StateEngineOff(self)

    def on(self):
        self.state.on();

    def off(self):
        self.state.off();

    def speed_up(self):
        self.state.speed_up()


class StateEngineOff(StateEngine):
    def __init__(self, jet: FighterJet):
        self.jet = jet

    def on(self):
        print("ENGINE ON")
        self.jet.state = StateEngineOn(self.jet)

    def off(self):
        print("ENGINE ALREADY STOPPED")

    def speed_up(self):
        print("CANNOT SPEED UP STOPPED ENGINE")
        pass


class StateEngineOn(StateEngine):
    def __init__(self, jet: FighterJet):
        self.jet = jet

    def on(self):
        print("ENGINE ALREADY STARTED")

    def off(self):
        print("ENGINE OFF")
        self.jet.state = StateEngineOff(self.jet)

    def speed_up(self):
        print("SPEED UP BY 10")
        self.jet.speed += 10


fighter_f16 = FighterJet()
fighter_f16.off()
fighter_f16.speed_up()
fighter_f16.on()
fighter_f16.speed_up()
fighter_f16.on()
fighter_f16.off()
fighter_f16.off()
