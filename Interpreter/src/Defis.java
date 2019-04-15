public class Defis extends Interpreter
{

    @Override
    public String interpret(String text)
    {
        text.replace('-', '—');
        return text;
    }
}
