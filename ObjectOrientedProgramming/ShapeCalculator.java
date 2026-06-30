package Casting_Conundrum;

class ShapeCalculator {

        static void calculateAndPrint(Shapes[] shapes) {
            //to take an array of shapes as input
            //and perform the casting and calculations

                for(Shapes shape : shapes){
                        if(shape instanceof Circle){
                                ((Circle) shape).calculate();
                        } else if (shape instanceof Square) {
                                ((Square) shape).calculate();
                        } else if (shape instanceof Triangle){
                                ((Triangle) shape).calculate();
                        }
                }

        }
}
