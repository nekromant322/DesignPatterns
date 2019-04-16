public class Terrorist extends Person {
    private int luggage = 0;

    public Terrorist(int luggage){
        this.luggage=luggage;
    }

    public String info(){
        return "Terrorist with "+luggage+" kg of luggage\n";
    }

    public int getLuggage(){
        return luggage;
    }
    public void getOutExtra(){
        luggage = 0;
    }
    public void remove(){}
}
