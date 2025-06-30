package Phonecall;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

enum State {
    OFF_HOOK,
    ON_HOOK,
    CONNECTING,
    CONNECTED,
    ON_HOLD
};

enum Trigger {
    CALL_DIALED,
    HANG_UP,
    CALL_CONECTED,
    PLACED_ON_HOLD,
    TAKEN_OF_HOLD,
    LEFT_MESSAGE,
    STOP_USING_PHONE
};

class Demo {
    private static final Map<State, Map<Trigger, State>> rules = new HashMap<>();

    static {
        rules.put(State.OFF_HOOK, Map.of(
                Trigger.CALL_DIALED, State.CONNECTING,
                Trigger.STOP_USING_PHONE, State.ON_HOOK
        ));
        rules.put(State.CONNECTING, Map.of(
                Trigger.HANG_UP, State.OFF_HOOK,
                Trigger.CALL_CONECTED, State.CONNECTED
        ));
        rules.put(State.CONNECTED, Map.of(
                Trigger.LEFT_MESSAGE, State.OFF_HOOK,
                Trigger.HANG_UP, State.OFF_HOOK,
                Trigger.PLACED_ON_HOLD, State.ON_HOLD
        ));
        rules.put(State.ON_HOLD, Map.of(
                Trigger.TAKEN_OF_HOLD, State.CONNECTED,
                Trigger.HANG_UP, State.OFF_HOOK
        ));
    }

    private static State currentState = State.OFF_HOOK;
    private static State exitState = State.ON_HOOK;

    public static void main(String[] args) {
        BufferedReader console = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            System.out.println("El telefono esta actualmente:  " + currentState);
            System.out.println("Selecciona una accion");

            Map<Trigger, State> options = rules.get(currentState);

            List<Trigger> triggers = new ArrayList<>(options.keySet());
            for (int i = 0; i < triggers.size(); i++) {
                System.out.println(i + ". " + triggers.get(i));
            }

            boolean parseOK=false;
            int choice = -1;
            do {
                try {
                    choice = Integer.parseInt(console.readLine());
                    if (choice < 0 || choice >= triggers.size()) {
                        System.out.println("Numero Invalido.");
                        continue;
                    }
                    parseOK = true;
                } catch (NumberFormatException e) {
                    System.out.println("Ingresa un numero valido.");
                    continue;
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            } while (!parseOK);
            currentState = options.get(triggers.get(choice));
            if(currentState == exitState) break;
        }
        System.out.println("Goodbye!");
    }
}
