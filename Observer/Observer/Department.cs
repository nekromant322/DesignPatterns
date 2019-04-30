using System;
using System.Collections.Generic;

namespace Observer
{
    class Department : IObserver
    {
        IObservable deanery;
        public Department(IObservable o)
        {
            deanery = o;
            deanery.RegisterObserver(this);
        }
        public void Update(Object o)
        {
            if (o is List<string> names)
            {
                Console.WriteLine($"Кафедра получила список из {names.Count} преподавателей, не сдавших отчёт.");
                if (names.Count > 0)
                {
                    Console.WriteLine("Не сдали отчет:");
                    foreach (string n in names)
                        Console.WriteLine(n);
                }
                Console.WriteLine("------------------------------------------"); 
            }
            else
            {
                throw new Exception("Всё плохо");
            }
        }
    }
}
