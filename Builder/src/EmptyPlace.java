public class EmptyPlace extends Person {
    public String info(){
        return "Empty place\n";
    }

    public int getLuggage(){
        return 0;
    }

    @Override
    public void getOutExtra() {}
    public void remove(){}
}
