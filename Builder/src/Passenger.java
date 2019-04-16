public class Passenger extends Person {

    private int luggage = 0;

    public Passenger(int luggage){
        this.luggage=luggage;
    }

    public String info(){
        if(luggage != 0)
        return "Passenger with "+luggage+" kg of luggage\n";
        else return "Passenger got out \n";

    }

    public int getLuggage(){
        return luggage;
    }
    public void getOutExtra(){

        luggage = 0;
    }
    public void remove(){}
}
