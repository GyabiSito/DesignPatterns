package Factory;

class Point2 {
    private double x, y;

    private Point2(double x, double y) {
        this.x = x;
        this.y = y;
    }
    public static class Factory{
        public static Point2 newCartesianPoint(double x, double y) {
            return new Point2(x,y);
        }
        public static Point2 newPolarPoint(double x, double y) {
            return new Point2((x*Math.cos(y)),(x*Math.sin(y)));
        }
    }
}

class Demo2{
    public static void main(String[] args) {
        Point2.Factory.newPolarPoint(1,2);
        Point2.Factory.newCartesianPoint(1,2);
    }
}