package OpenClose;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;

enum Color {
    RED, BLUE, GREEN
}

enum Size {
    SMALL, MEDIUM, LARGE, YUGE
}

class Product {
    public String name;
    public Color color;
    public Size size;

    public Product(String name, Color color, Size size) {
        this.name = name;
        this.color = color;
        this.size = size;
    }
}

class ProductFilter {
    public Stream<Product> filterByColor(List<Product> products, Color color) {
        return products.stream().filter(product -> product.color == color);
    }

    public Stream<Product> filterBySize(List<Product> products, Size size) {
        return products.stream().filter(product -> product.size == size);
    }

    public Stream<Product> filterBySizeAndColor(List<Product> products, Size size, Color color) {
        return products.stream().filter(product -> product.color == color && product.size == size);
    }
}

interface Specification<T> {
    boolean isSatisfied(T item);
}

interface Filter<T> {
    Stream<T> filter(List<T> items, Specification<T> spec);
}

class ColorSpecification implements Specification<Product> {
    private Color color;

    public ColorSpecification(Color color) {
        this.color = color;
    }

    @Override
    public boolean isSatisfied(Product product) {
        return this.color == product.color;
    }
}

class SizeSpecification implements Specification<Product> {
    private Size size;

    public SizeSpecification(Size size) {
        this.size = size;
    }

    @Override
    public boolean isSatisfied(Product product) {
        return this.size == product.size;
    }
}

class BetterFilter implements Filter<Product> {
    @Override
    public Stream<Product> filter(List<Product> items, Specification<Product> spec) {
        return items.stream().filter(spec::isSatisfied);
    }
}
class AndSpecification<T> implements Specification<T> {
    private Specification<T> first, second;
    public AndSpecification(Specification<T> first, Specification<T> second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public boolean isSatisfied(T item) {
        return first.isSatisfied(item) && second.isSatisfied(item);
    }
}
class Demo {
    public static void main(String[] args) {
        Product p1 = new Product("p1", Color.RED, Size.MEDIUM);
        Product p2 = new Product("p2", Color.BLUE, Size.LARGE);
        Product p3 = new Product("p3", Color.GREEN, Size.YUGE);
        Product p4 = new Product("p4", Color.RED, Size.LARGE);
        Product p5 = new Product("p5", Color.BLUE, Size.LARGE);

        List<Product> products = Arrays.asList(p1, p2, p3, p4, p5);

        ProductFilter filter = new ProductFilter();
        System.out.println("Green products: (old) ");
        filter.filterByColor(products, Color.GREEN).forEach(p -> System.out.println(p.name));
        BetterFilter betterFilter = new BetterFilter();


        System.out.println("Green products: (new) ");
        betterFilter.filter(products,new ColorSpecification(Color.GREEN)).forEach(p -> System.out.println(p.name));

        System.out.println("LOarge and Red products (new) ");
        betterFilter.filter(products, new AndSpecification<>(
                new ColorSpecification(Color.RED),
                new SizeSpecification(Size.LARGE)
        )).forEach(p-> System.out.println("P es Large and Red " + p.name));



    }


}
