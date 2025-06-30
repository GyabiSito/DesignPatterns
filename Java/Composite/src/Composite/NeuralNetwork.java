package Composite;

import java.util.*;
import java.util.function.Consumer;

interface SomeNeurons extends Iterable<Neuron> {
    default void connectTo(SomeNeurons other){
        if(this==other) return;
        for(Neuron n : this){
            for(Neuron to : other){
                n.out.add(to);
                to.in.add(n);
                System.out.println("Connected to " + n + " to " + to);
            }
        }
    }
}

class Neuron implements SomeNeurons {
    public ArrayList<Neuron> in, out;


    @Override
    public Spliterator<Neuron> spliterator() {
        return Collections.singleton(this).spliterator();
    }

    @Override
    public Iterator<Neuron> iterator() {
        return Collections.singleton(this).iterator();
    }

    @Override
    public void forEach(Consumer<? super Neuron> action) {
        action.accept(this);
    }
}

class NeuronLayer extends ArrayList<Neuron> implements SomeNeurons {
}

class Demo {
    public static void main(String[] args) {

        Neuron neuron = new Neuron();
        Neuron neuron1 = new Neuron();
        NeuronLayer neuronLayer = new NeuronLayer();
        NeuronLayer neuronLayer1 = new NeuronLayer();

        neuron.connectTo(neuron1);

    }
}