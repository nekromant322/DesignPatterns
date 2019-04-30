using System;

namespace Observer
{
    class Program
    {
        static void Main(string[] args)
        {
            Clock clock = new Clock();
            Deanery deanery = new Deanery(clock);
            Department dep = new Department(deanery);
            Teacher t1 = new Teacher("Teacher1", deanery);
            Teacher t2 = new Teacher("Teacher2", deanery);
            Teacher t3 = new Teacher("Teacher3", deanery);
            //t1.WriteReport();
            clock.NotifyObservers();
            t2.WriteReport();
            t1.WriteReport();
            t3.WriteReport();
            clock.NotifyObservers();
            deanery.RemoveTeacher(t3);
            clock.NotifyObservers();
            Console.ReadKey();
        }
    }
}
