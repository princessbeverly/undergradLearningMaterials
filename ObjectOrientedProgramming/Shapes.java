    /*  ALETHEA JOY MONYK P. SANCHEZ
*   BSCS 2 - CRS1
*   ACTIVITY 5 - OBJECT TYPECASTING   */

package Casting_Conundrum;

abstract class Shapes {

   abstract void calculate();

    public static void main (String[] args) {

        //upcasting - subclass to superclass
        //Shapes shapes = new Circle();

        //Downcasting - superclass to subclass
        //Square square = (Square) shapes;

        Shapes[] shapes;
        shapes = new Shapes[3];
        shapes[0] = new Circle(5);
        shapes[1] = new Square(9.8);
        shapes[2] = new Triangle(10.145, 13.56);

        ShapeCalculator.calculateAndPrint(shapes);
    }

}

//subclasses
class Circle extends Shapes {

    double radius;
    float pi = 3.14f;

    Circle(double radius){
        this.radius = radius;
    }

    @Override
    void calculate(){
        double area = pi * radius * radius;
        System.out.println("Area of circle: " + String.format("%.2f", area));
    }

}

class Square extends Shapes {

    double sidelen;

    Square(double sidelen){
        this.sidelen = sidelen;

    }

    @Override
    void calculate(){
        double perimeter = 4 * sidelen;
        System.out.println("Perimeter of square: " + String.format("%.2f", perimeter));
    }
}

class Triangle extends Shapes {

    double base, height;

    Triangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    @Override
    void calculate() {
        double hypotenuse = Math.sqrt(base * base + height * height);
        System.out.println("Hypotenuse length of triangle: " + String.format("%.2f", hypotenuse));
    }
}