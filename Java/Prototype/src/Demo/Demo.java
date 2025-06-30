package Demo;

import java.util.Arrays;


class Address implements Cloneable {
    public String streetName;
    public int houseNumber;

    public Address(String streetName, int houseNumber)
    {
        this.streetName = streetName;
        this.houseNumber = houseNumber;
    }

    @Override
    public String toString()
    {
        return "Address{" +
                "streetName='" + streetName + '\'' +
                ", houseNumber=" + houseNumber +
                '}';
    }

    // clone() es protected
    @Override
    public Object clone() throws CloneNotSupportedException
    {
        return new Address(streetName, houseNumber);
    }
}

class Person implements Cloneable
{
    public String [] names;
    public Address address;

    public Person(String[] names, Address address)
    {
        this.names = names;
        this.address = address;
    }

    @Override
    public String toString()
    {
        return "Person{" +
                "names=" + Arrays.toString(names) +
                ", address=" + address +
                '}';
    }

    @Override
    public Object clone() throws CloneNotSupportedException
    {
        return new Person(

                names.clone(),

                address instanceof Cloneable ? (Address) address.clone() : address
        );
    }
}

class CloneableDemo
{
    public static void main(String[] args)
            throws CloneNotSupportedException
    {
        Person john = new Person(new String[]{"John", "Smith"},
                new Address("London Road", 123));

        // Copia superficial:
        //Person jane = john;

        Person jane = (Person) john.clone(); // Aca ya no se cambia el valor en memoria
        jane.names[0] = "Jane";
        jane.address.houseNumber = 124; // Esto tambien cambia a jhon por ser la misma direccion de memoria SI usamos jane=jhon

        System.out.println(john);
        System.out.println(jane);
    }
}
