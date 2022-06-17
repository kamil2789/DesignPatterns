class IndustryObject:
    def accept(self, visitor):
        pass

    def work(self):
        pass


class CarFactory(IndustryObject):
    def accept(self, visitor):
        visitor.visit(self)

    def work(self):
        return 500


class FurnitureFactory(IndustryObject):
    def accept(self, visitor):
        visitor.visit(self)

    def work(self):
        return 2000


class IndustryVisitor:
    def visit(self, factory: CarFactory):
        pass

    def visit(self, factory: FurnitureFactory):
        pass


class PrinterVisitor(IndustryVisitor):
    def visit(self, factory: CarFactory):
        print(f"Inspection for car factory: effectivness {factory.work()}")

    def visit(self, factory: FurnitureFactory):
        print(f"Inspection for furniture factory: effectivness {factory.work()}")


toyota = CarFactory()
amba = FurnitureFactory()
inspector = PrinterVisitor()

toyota.accept(inspector)
amba.accept(inspector)


