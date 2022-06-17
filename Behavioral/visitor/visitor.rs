
trait IndustryVisitor {
    fn visit_car_factory(&self, item: &CarFactory);
    fn visit_furniture_factory(&self, item: &FurnitureFactory);
}

trait Visitable {
    fn accept(&self, visitor: &dyn IndustryVisitor);
}

trait IndustryObject {
    fn work(&self) -> u32;
}

struct PrinterVisitor {

}

impl IndustryVisitor for PrinterVisitor {
    fn visit_car_factory(&self, item: &CarFactory) {
        println!("Inspection for car factory: effectivness {}", item.work());
    }

    fn visit_furniture_factory(&self, item: &FurnitureFactory) {
        println!("Inspection for furniture factory: effectivness {}", item.work());
    }
}

struct CarFactory {

}

struct FurnitureFactory {

}

impl IndustryObject for CarFactory {
    fn work(&self) -> u32 {
        500
    }
}

impl IndustryObject for FurnitureFactory {
    fn work(&self) -> u32 {
        2000
    }
}

impl Visitable for CarFactory {
    fn accept(&self, visitor: &dyn IndustryVisitor) {
        visitor.visit_car_factory(self);
    }
}

impl Visitable for FurnitureFactory {
    fn accept(&self, visitor: &dyn IndustryVisitor) {
        visitor.visit_furniture_factory(self);
    }
}

fn main() {
    let car_factory = CarFactory{};
    let furniture_factory = FurnitureFactory{};

    let inspector = PrinterVisitor{};

    car_factory.accept(&inspector);
    furniture_factory.accept(&inspector);
}