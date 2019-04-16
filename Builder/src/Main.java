import java.util.Random;

public class Main {

    private static PassengerClass makeClass(String name,int maxPas,int maxLang){
        PassengerClass cl=new PassengerClass(name,maxLang);
        Person p;
        Random random=new Random();
        for (int i = 0; i < maxPas; i++) {
            if(random.nextInt(200)==155)
                p= new Terrorist(random.nextInt(40));
            else
                p = new Passenger(random.nextInt(70));
            cl.add(p);
        }
        return cl;
    }

    public static void main(String Args[])
    {
        PassengerClass plane=new PassengerClass("Plane",3000);
        for(int i=0;i<2;i++)
            plane.add(new Pilot());
        for(int i=0;i<6;i++)
            plane.add(new Stewardess());
        plane.add(makeClass("First class",10,-1));
        plane.add(makeClass("Business class",10,35));
        plane.add(makeClass("Econom class",150,20));
        plane.getOutExtra();
        System.out.println(plane.info());
        System.out.println(plane.getLuggage());
        plane.remove();
        System.out.println(plane.info());
        //plane.getOutExtra();
    }
}
