package Factory;

enum CoordinateSystem {
    CARTESIAN, POLAR
}

class Point {
    private double x, y;

    private Point(double x, double y) {
        this.x = x;
        this.y = y;
    }
//    private Point(double x, double y, CoordinateSystem coordinateSystem) {
//        switch (coordinateSystem) {
//            case CARTESIAN:
//                this.x = x;
//                this.y = y;
//                break;
//            case POLAR:
//                this.x = x * Math.cos(y);
//                this.y = x * Math.sin(y);
//                break;
//            default:
//                break;
//        }
//    }
    public static Point newCartesianPoint(double x, double y) {
        return new Point(x++,y);
    }
    public static Point newPolarPoint(double x, double y) {
        return new Point((x*Math.cos(y)),(x*Math.sin(y)));
    }
}

class Demo{
    public static void main(String[] args) {
        Point.newPolarPoint(1,2);
        Point.newCartesianPoint(1,2);
    }
}