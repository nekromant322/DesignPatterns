import java.util.ArrayList;

public class PassengerClass extends Person {

    private String name;
    private ArrayList<Person> passengers=new ArrayList<>();
    private int maxWeight;

    public PassengerClass(String name,int max){
        this.name=name;
        this.maxWeight=max;
    }

    public void add(Person p){

        passengers.add(p);
        /*if(p.getLuggage()>maxWeight && name == "Econom class") {
            //Выкидываем пассажира
            System.out.println("Passenger with "+ p.getLuggage() + "kg got out \n");
        }
        else{
            passengers.add(p);
        }*/
    }

    public int getLuggage(){
        int w=0;
        for(int i=0;i<passengers.size();i++){

            w=w+passengers.get(i).getLuggage();

        }
        return w;
    }

    public void getOutExtra(){
        if(name=="Econom class")
        {
            for(int i=0;i<passengers.size();i++)
            {
                if(passengers.get(i).getLuggage()>maxWeight)
                {
                    //System.out.println("Passenger with number " + i + " get out extra weight\n");
                    passengers.get(i).getOutExtra();

                        //Выкидываем пассажира
                        System.out.println("Passenger with "+ passengers.get(i).getLuggage() + "kg got out \n");
                    //passengers.remove(i);



                }
            }
        }
        else
        {
            for (int i = 0; i < passengers.size(); i++)
            {
                passengers.get(i).getOutExtra();
            }
        }
    }

    public String info() {
        String classInfo = "There is a " + name + "\n";
        for (int i = 0; i < passengers.size(); i++) {
            classInfo = classInfo + i + " ." + passengers.get(i).info();
        }
        return classInfo;
    }
    public void remove(){
        for(int i=0;i<passengers.size();i++)
            if(passengers.get(i).info().startsWith("Terrorist")){
                System.out.println("Terrorist with number "+i+ " removed\n");
                passengers.remove(i);
                passengers.add(i,new EmptyPlace());
            }
            else{
                passengers.get(i).remove();
            }
    }
}
